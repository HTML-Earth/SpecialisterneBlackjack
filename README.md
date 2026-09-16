# Specialisterne Blackjack project
Simple C++ implementation of Blackjack

# UML diagram
```mermaid
    classDiagram
    Application : main()
    Application : loop()
    Application -- InputHandler
    InputHandler : handleInput()
    InputHandler -- BlackjackGame
    BlackjackGame : Spot deck
    BlackjackGame : Spot playerHand
    BlackjackGame : Spot houseHand
    BlackjackGame : startGame()
    BlackjackGame : hit()
    BlackjackGame : stay()
    BlackjackGame -- CardManager
    CardManager : Card[] createDeck()
    CardManager : drawCard(Spot,Spot)
    BlackjackGame o-- Spot
    Spot : Card[] cards
    Spot : Card[] getCards()
    Spot : addCard(Card)
    Spot : shuffleCards()
    Spot : Card removeTopCard()
    Spot o-- Card
    Card : Suit { hearts, diamonds, spades, clubs }
    Card : int getValue(Card[])
    Card : string getCardName()
    Card <|-- NumberCard
    NumberCard : int number
    Card <|-- FaceCard
    FaceCard : Character { jack, queen, king }
    Card <|-- AceCard
%%    C1 *--o C2
%%    C3 <--> C4 : label
%%    C3 ..* C5
```

# Building
- Install vcpkg and catch2
- Add env variable: `VCPKG_INCLUDE_PATH` (something like `C:/Users/~name~/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic/include`)