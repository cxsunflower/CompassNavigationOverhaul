"""Generate original, opaque RGBA diagnostic artwork. No third-party font/texture assets."""
import argparse
import struct
from pathlib import Path

FONT = {
'A':['01110','10001','10001','11111','10001','10001','10001'],
'D':['11110','10001','10001','10001','10001','10001','11110'],
'E':['11111','10000','10000','11110','10000','10000','11111'],
'F':['11111','10000','10000','11110','10000','10000','10000'],
'I':['111','010','010','010','010','010','111'],
'L':['10000','10000','10000','10000','10000','10000','11111'],
'M':['10001','11011','10101','10101','10001','10001','10001'],
'N':['10001','11001','10101','10011','10001','10001','10001'],
'O':['01110','10001','10001','10001','10001','10001','01110'],
'P':['11110','10001','10001','11110','10000','10000','10000'],
'Q':['01110','10001','10001','10001','10101','10010','01101'],
'S':['01111','10000','10000','01110','00001','00001','11110'],
'T':['11111','00100','00100','00100','00100','00100','00100'],
'U':['10001','10001','10001','10001','10001','10001','01110'],
'X':['10001','10001','01010','00100','01010','10001','10001'],
'Z':['11111','00001','00010','00100','01000','10000','11111'],
' ':['000']*7,
}

def generate(path):
    w,h=512,256
    data=bytearray(bytes((9,18,27,255))*(w*h))
    def rect(x,y,r,b,color):
        for yy in range(max(0,y),min(h,b)):
            for xx in range(max(0,x),min(w,r)):
                data[4*(yy*w+xx):4*(yy*w+xx)+4]=bytes((*color,255))
    def text(label,y,scale,color):
        width=sum((len(FONT[c][0])+1)*scale for c in label)-scale
        x=(w-width)//2
        for c in label:
            for yy,row in enumerate(FONT[c]):
                for xx,bit in enumerate(row):
                    if bit=='1':rect(x+xx*scale,y+yy*scale,x+(xx+1)*scale,y+(yy+1)*scale,color)
            x+=(len(FONT[c][0])+1)*scale
    cyan=(60,220,240);white=(235,245,250)
    rect(0,0,w,5,cyan);rect(0,h-5,w,h,cyan)
    rect(0,0,5,h,cyan);rect(w-5,0,w,h,cyan)
    text('PALM TEST',28,5,white)
    text('FIXED SIZE',91,4,cyan)
    text('NO QUEST DATA',151,3,white)
    rect(26,220,486,223,cyan)
    for i in range(13):
        x=26+round(i*460/12)
        rect(x,207 if i%3==0 else 214,x+2,233,cyan)
    for x,y,c in [(6,6,(70,240,100)),(486,6,(250,90,70)),(6,230,(80,130,250)),(486,230,(250,220,80))]:
        rect(x,y,x+20,y+20,c)
    # DDS_HEADER: pitch, RGBA masks, one mip; alpha is always 255.
    values=[124,0x100F,h,w,w*4,0,0]+[0]*11+[32,0x41,0,32,0xFF,0xFF00,0xFF0000,0xFF000000]+[0x1000,0,0,0,0]
    header=b'DDS '+struct.pack('<31I',*values)
    path=Path(path);path.parent.mkdir(parents=True,exist_ok=True)
    path.write_bytes(header+data)
    assert len(path.read_bytes())==128+w*h*4
    print('Generated 512x256 opaque RGBA DDS with original bitmap labels and ruler')

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('output');a=p.parse_args();generate(a.output)
