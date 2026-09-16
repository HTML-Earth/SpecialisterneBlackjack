project(Cards)

set(HEADER_FILES
        Card.h
        AceCard.h
        FaceCard.h
        NumberCard.h
        CardManager.h
)

set(SOURCE_FILES
        AceCard.cpp
        FaceCard.cpp
        NumberCard.cpp
        CardManager.cpp
)

add_library(Cards_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})