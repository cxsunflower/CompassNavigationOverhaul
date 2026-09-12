# Record the configuration of the DLL actually linked, not just the current cache.
file(SHA256 "${DLL}" DLL_SHA256)
if(PALMTEST)
    set(PALMTEST_JSON true)
else()
    set(PALMTEST_JSON false)
endif()
file(WRITE "${DLL}.build-profile.json" "{\"palmtest\":${PALMTEST_JSON},\"sha256\":\"${DLL_SHA256}\"}\n")
