option(QT_AVPLAYER_MULTIMEDIA "Enable QtMultimedia" OFF)
option(QT_AVPLAYER_VA_X11 "Enable libva-x11" OFF)
option(QT_AVPLAYER_VA_DRM "Enable libva-drm" OFF)
option(QT_AVPLAYER_VDPAU "Enable vdpau" OFF)

set(QtAVPlayer_PRIVATE_HEADERS
    qavcodec_p.h
    qavcodec_p_p.h
    qavframecodec_p.h
    qavaudiocodec_p.h
    qavvideocodec_p.h
    qavsubtitlecodec_p.h
    qavhwdevice_p.h
    qavdemuxer_p.h
    qavpacket_p.h
    qavstreamframe_p.h
    qavframe_p.h
    qavpacketqueue_p.h
    qavvideobuffer_p.h
    qavvideobuffer_cpu_p.h
    qavvideobuffer_gpu_p.h
    qavfilter_p.h
    qavfilter_p_p.h
    qavvideofilter_p.h
    qavaudiofilter_p.h
    qavfiltergraph_p.h
    qavinoutfilter_p.h
    qavinoutfilter_p_p.h
    qavvideoinputfilter_p.h
    qavaudioinputfilter_p.h
    qavvideooutputfilter_p.h
    qavaudiooutputfilter_p.h
    qavfilters_p.h
)

set(QtAVPlayer_PUBLIC_HEADERS
    qaviodevice.h
    qavaudioformat.h
    qavstreamframe.h
    qavframe.h
    qavvideoframe.h
    qavaudioframe.h
    qavsubtitleframe.h
    qtavplayerglobal.h
    qavstream.h
    qavplayer.h
)

set(QtAVPlayer_SOURCES
    qavplayer.cpp
    qavcodec.cpp
    qavframecodec.cpp
    qavaudiocodec.cpp
    qavvideocodec.cpp
    qavsubtitlecodec.cpp
    qavdemuxer.cpp
    qavpacket.cpp
    qavframe.cpp
    qavstreamframe.cpp
    qavvideoframe.cpp
    qavaudioframe.cpp
    qavsubtitleframe.cpp
    qavvideobuffer_cpu.cpp
    qavvideobuffer_gpu.cpp
    qavfilter.cpp
    qavvideofilter.cpp
    qavaudiofilter.cpp
    qavfiltergraph.cpp
    qavinoutfilter.cpp
    qavvideoinputfilter.cpp
    qavaudioinputfilter.cpp
    qavvideooutputfilter.cpp
    qavaudiooutputfilter.cpp
    qaviodevice.cpp
    qavstream.cpp
    qavfilters.cpp
)

if(WIN32)
    set(QtAVPlayer_PRIVATE_HEADERS
        ${QtAVPlayer_PRIVATE_HEADERS}
        qavhwdevice_d3d11_p.h
    )

    set(QtAVPlayer_SOURCES
        ${QtAVPlayer_SOURCES}
        qavhwdevice_d3d11.cpp
    )
endif()

if(APPLE)
    set(QtAVPlayer_SOURCES
        ${QtAVPlayer_SOURCES}
        qavhwdevice_videotoolbox.mm
    )
endif()

if(ANDROID)
    set(QtAVPlayer_SOURCES
        ${QtAVPlayer_SOURCES}
        qavhwdevice_mediacodec.cpp
        qavandroidsurfacetexture.cpp
    )
endif()

if(QT_AVPLAYER_MULTIMEDIA)
    message(STATUS "QT_AVPLAYER_MULTIMEDIA is defined")
    add_definitions(-DQT_AVPLAYER_MULTIMEDIA)

    set(QtAVPlayer_PUBLIC_HEADERS
        ${QtAVPlayer_PUBLIC_HEADERS}
        qavaudiooutput.h
        qavaudiooutputdevice.h
    )

    set(QtAVPlayer_SOURCES
        ${QtAVPlayer_SOURCES}
        qavaudiooutput.cpp
        qavaudiooutputdevice.cpp
    )
endif()

if(QT_AVPLAYER_VA_X11)
    message(STATUS "QT_AVPLAYER_VA_X11 is defined")
    add_definitions(-DQT_AVPLAYER_VA_X11)

    set(QtAVPlayer_LIBS
        ${QtAVPlayer_LIBS}
        OpenGL::GL
        X11
        va-x11
        va
    )

    set(QtAVPlayer_PRIVATE_HEADERS
        ${QtAVPlayer_PRIVATE_HEADERS}
        qavhwdevice_vaapi_x11_glx_p.h
    )

    set(QtAVPlayer_SOURCES
        ${QtAVPlayer_SOURCES}
        qavhwdevice_vaapi_x11_glx.cpp
    )
endif()

if(QT_AVPLAYER_VA_DRM)
    message(STATUS "QT_AVPLAYER_VA_DRM is defined")

    # Search for the drm_fourcc.h file in both possible locations
    find_path(DRM_FOURCC_H_PATH drm_fourcc.h
            PATHS
            /usr/include/drm
            /usr/include/libdrm
            NO_DEFAULT_PATH
    )

    # Check if the file was found
    if (DRM_FOURCC_H_PATH)
        message(STATUS "Found drm_fourcc.h at ${DRM_FOURCC_H_PATH}")

        # Check if the file is in both locations and prefer the drm version
        find_path(DRM_PATH drm_fourcc.h PATHS /usr/include/drm NO_DEFAULT_PATH)
        if (DRM_PATH AND DRM_PATH STREQUAL DRM_FOURCC_H_PATH)
            message(STATUS "Using /usr/include/drm version of drm_fourcc.h")
            include_directories(/usr/include/drm)
        else()
            message(STATUS "Using ${DRM_FOURCC_H_PATH} version of drm_fourcc.h")
            include_directories(${DRM_FOURCC_H_PATH})
        endif()
    else()
        message(FATAL_ERROR "drm_fourcc.h not found in the specified paths")
    endif()

    add_definitions(-DQT_AVPLAYER_VA_DRM)

    find_package(OpenGL REQUIRED COMPONENTS OpenGL EGL)
    set(QtAVPlayer_LIBS
        ${QtAVPlayer_LIBS}
        OpenGL::GL
        EGL
        va-drm
        va
    )

    set(QtAVPlayer_PRIVATE_HEADERS
        ${QtAVPlayer_PRIVATE_HEADERS}
        qavhwdevice_vaapi_drm_egl_p.h
    )

    set(QtAVPlayer_SOURCES
        ${QtAVPlayer_SOURCES}
        qavhwdevice_vaapi_drm_egl.cpp
    )
endif()

if(QT_AVPLAYER_VDPAU)
    message(STATUS "QT_AVPLAYER_VDPAU is defined")
    add_definitions(-DQT_AVPLAYER_VDPAU)

    find_package(OpenGL REQUIRED)
    set(QtAVPlayer_LIBS
        ${QtAVPlayer_LIBS}
        OpenGL::GL
    )

    set(QtAVPlayer_PRIVATE_HEADERS
        ${QtAVPlayer_PRIVATE_HEADERS}
        qavhwdevice_vdpau_p.h
    )

    set(QtAVPlayer_SOURCES
        ${QtAVPlayer_SOURCES}
        qavhwdevice_vdpau.cpp
    )
endif()


add_library(QtAVPlayer STATIC
    ${QtAVPlayer_SOURCES}
    ${QtAVPlayer_PUBLIC_HEADERS}
    ${QtAVPlayer_PRIVATE_HEADERS}
)

target_link_libraries(QtAVPlayer PUBLIC
    ${QT_VERSION_BASE}::Core
    ${QT_VERSION_BASE}::Gui
    ${QT_VERSION_BASE}::Multimedia
    ${QT_VERSION_BASE}::MultimediaPrivate
    ${QT_VERSION_BASE}::Widgets
    ${FFMPEG_LIBRARIES}
    ${QtAVPlayer_LIBS}
)

target_include_directories(QtAVPlayer
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${FFMPEG_INCLUDE_DIRS}
)