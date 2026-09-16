project(Cards)

set(HEADER_FILES
        Card.h
        AceCard.h
        FaceCard.h
        NumberCard.h
        CardManager.h
        Spot.h
)

set(SOURCE_FILES
        AceCard.cpp
        FaceCard.cpp
        NumberCard.cpp
        CardManager.cpp
        Spot.cpp
)

add_library(Cards_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})