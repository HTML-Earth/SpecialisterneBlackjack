# Specialisterne Blackjack project
Simple C++ implementation of Blackjack

# UML diagram
```mermaid
    classDiagram
    Application : main()
    Application -- BlackjackGame
    BlackjackGame : enum GameState
    BlackjackGame : enum EndCondition
    BlackjackGame : GameState m_currentState
    BlackjackGame : int m_currentRound
    BlackjackGame : bool m_playerStayed
    BlackjackGame : bool m_houseStayed
    BlackjackGame : EndCondition m_endCondition
    BlackjackGame : bool m_shortOutputIsEnabled
    BlackjackGame : Spot m_deck
    BlackjackGame : Spot m_playerHand
    BlackjackGame : Spot m_houseHand
    BlackjackGame : startGame()
    BlackjackGame : hit()
    BlackjackGame : stand()
    BlackjackGame : toggleShort()
    BlackjackGame -- CardManager
    CardManager : static Card[] createDeck()
    CardManager : static drawCard(Spot,Spot)
    BlackjackGame o-- Spot
    Spot : Card[] m_cards
    Spot : Card[] getCards()
    Spot : int getCombinedValue()
    Spot : addCard(Card)
    Spot : shuffleCards()
    Spot : Card removeTopCard()
    Spot : void clear()
    Spot o-- Card
    Card : enum Suit
    Card : Suit m_suit
    Card : int getValue(Card[])
    Card : string getCardName()
    Card <|-- NumberCard
    NumberCard : int number
    Card <|-- FaceCard
    FaceCard : enum Character
    FaceCard : Character m_character
    FaceCard : static string getCharacterName(Character)
    FaceCard : static string getCharacterLetter(Character)
    Card <|-- AceCard
    CardTests -- CardManager
    BlackjackTests -- TestableBlackjackGame
    TestableBlackjackGame --|> BlackjackGame
    TestableBlackjackGame : GameState getCurrentState()
    TestableBlackjackGame : int getCurrentRound()
    TestableBlackjackGame : bool getPlayerStayed()
    TestableBlackjackGame : bool getHouseStayed()
    TestableBlackjackGame : EndCondition getEndCondition()
    TestableBlackjackGame : Spot getDeck()
    TestableBlackjackGame : Spot getPlayerHand()
    TestableBlackjackGame : Spot getHouseHand()
%%    C1 *--o C2
%%    C3 <--> C4 : label
%%    C3 ..* C5
```

# Building the application
- Install `catch2` and `fmt` (I used `vcpkg`)
- `.idea/cmake.xml` contains these env variables used by `CMakeLists.txt` to include the "standard" libraries in the build folder:
  - `LIB_GCC_NAME` = `libgcc_s_seh-1.dll`
  - `LIB_PTHREAD_NAME` = `libwinpthread-1.dll`
  - `LIB_STD_NAME` = `libstdc++-6.dll`
  - `MINGW64_BINARIES_PATH` = `$PROJECT_DIR$/../../../../Program Files/Git/mingw64/bin/`
  - If MingW64 is installed elsewhere, you'll have to change the binaries path.
  - If you're not using CLion you'll probably have to set them somewhere else.
  - Of course, if you're not using Windows, you don't have to worry about these .dlls.
