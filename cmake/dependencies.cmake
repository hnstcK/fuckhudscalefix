include(FetchContent)

# sampapi
FetchContent_Declare(
    sampapi
    GIT_REPOSITORY https://github.com/BlastHackNet/SAMP-API.git
    GIT_TAG "multiver"
)

FetchContent_MakeAvailable( sampapi )