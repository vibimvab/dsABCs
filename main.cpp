#include <SFML/Graphics.hpp>
#include "Algorithm.h"
#include "Dictionary.h"
#include "Word.h"
#include <iostream>
#include <fstream>
using namespace std;

//fonts sourced from www.1001freefonts.com
void setText(sf::Text& text, float x, float y) {
    //finds the local bounds of the text and changes it to be centered
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f,
        textBounds.top + textBounds.height / 2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

void setSprite(sf::Sprite& text, float x, float y) {
    //finds the local bounds of the Sprite and changes it to be centered
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f,
        textBounds.top + textBounds.height / 2.0f);
    text.setPosition(sf::Vector2f(x, y));
}


int main()
{
     //Text input for main screen
    string StringInput = "|";

    //sets width and height for pop up windows
    float Width = 1366, Height = 768, BoardSize = 15, TileCount = 7;
    bool WelcomeScreenOpen = true;

    sf::RenderWindow welcomeScreenWindow(sf::VideoMode(Width, Height), "dsABC's", sf::Style::Close);
    //the welcome screen font set-up
    sf::Font welcomeScreenFont;
    welcomeScreenFont.loadFromFile("../files/orange juice 2.0.ttf");

    // make texts
    sf::Text welcomeScreenTextLine1;
    welcomeScreenTextLine1.setFont(welcomeScreenFont);
    welcomeScreenTextLine1.setString("Welcome to");
    welcomeScreenTextLine1.setCharacterSize(64);
    welcomeScreenTextLine1.setFillColor(sf::Color::White);
    welcomeScreenTextLine1.setStyle(sf::Text::Bold);
    setText(welcomeScreenTextLine1, Width / 2.0f, Height / 2.0f - 270);

    sf::Text welcomeScreenTextLine2;
    welcomeScreenTextLine2.setFont(welcomeScreenFont);
    welcomeScreenTextLine2.setString("dsABC's");
    welcomeScreenTextLine2.setCharacterSize(200);
    welcomeScreenTextLine2.setFillColor(sf::Color::White);
    welcomeScreenTextLine2.setStyle(sf::Text::Bold);
    setText(welcomeScreenTextLine2, Width / 2.0f, Height / 2.0f - 120);

    sf::Text welcomeScreenTextLine3;
    welcomeScreenTextLine3.setFont(welcomeScreenFont);
    welcomeScreenTextLine3.setString("A Scrabble solving project by Insung Seo,");
    welcomeScreenTextLine3.setCharacterSize(50);
    welcomeScreenTextLine3.setFillColor(sf::Color::White);
    welcomeScreenTextLine3.setStyle(sf::Text::Bold);
    setText(welcomeScreenTextLine3, Width / 2.0f, Height / 2.0f + 30);

    sf::Text welcomeScreenTextLine4;
    welcomeScreenTextLine4.setFont(welcomeScreenFont);
    welcomeScreenTextLine4.setString("Emma Mitchell, and Chrystina Woehler");
    welcomeScreenTextLine4.setCharacterSize(50);
    welcomeScreenTextLine4.setFillColor(sf::Color::White);
    welcomeScreenTextLine4.setStyle(sf::Text::Bold);
    setText(welcomeScreenTextLine4, Width / 2.0f, Height / 2.0f + 30 + 50 + 10);

    sf::Text MainScreenInstructionText;
    MainScreenInstructionText.setFont(welcomeScreenFont);
    MainScreenInstructionText.setString("Enter up to 10 characters");
    MainScreenInstructionText.setCharacterSize(30);
    MainScreenInstructionText.setFillColor(sf::Color::Black);
    MainScreenInstructionText.setStyle(sf::Text::Bold);
    setText(MainScreenInstructionText, Width / 2.0f, Height / 2.0f + 140);

    sf::Text PossibleWordsText1;
    PossibleWordsText1.setFont(welcomeScreenFont);
    PossibleWordsText1.setCharacterSize(40);
    PossibleWordsText1.setFillColor(sf::Color::Black);
    PossibleWordsText1.setStyle(sf::Text::Bold);
    

    //Make sprites (buttons)
    sf::Sprite BeginButton;
    sf::Texture BeginButtonTexture;
    BeginButtonTexture.loadFromFile("../files/images/BeginButton.png");
    BeginButton.setTexture(BeginButtonTexture);
    setSprite(BeginButton, Width / 2.0f, Height / 2.0f + 50 + 50 + 140);

    sf::Sprite GenerateButton;
    sf::Texture GenerateButtonTexture;
    GenerateButtonTexture.loadFromFile("../files/images/GenerateButton.png");
    GenerateButton.setTexture(GenerateButtonTexture);
    setSprite(GenerateButton, Width / 2.0f, Height / 2.0f + 50 + 50 + 200);

    sf::Sprite Background;
    sf::Texture BackgroundTexture;
    BackgroundTexture.loadFromFile("../files/images/Background.png");
    Background.setTexture(BackgroundTexture);
    setSprite(Background, Width / 2.0f, Height / 2.0f);

    sf::Sprite PossibleWords;
    sf::Texture PossibleWordsTexture;
    PossibleWordsTexture.loadFromFile("../files/images/PossibleWord.png");
    PossibleWords.setTexture(PossibleWordsTexture);
    setSprite(PossibleWords, Width / 2.0f, Height / 2.0f - 140);

    sf::Sprite TextBox;
    sf::Texture TextBoxTexture;
    TextBoxTexture.loadFromFile("../files/images/TextBox.png");
    TextBox.setTexture(TextBoxTexture);
    setSprite(TextBox, Width / 2.0f, Height / 2.0f + 195);

    Dictionary dictionary;

    while (welcomeScreenWindow.isOpen()) {
        sf::Event event;
        while (welcomeScreenWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                welcomeScreenWindow.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                //Checks for left click
                if (event.mouseButton.button == sf::Mouse::Left) {
                    //gets current x,y of click
                    auto mouseX = event.mouseButton.x;
                    auto mouseY = event.mouseButton.y;
                 
                    //check if clicking begin button
                    if (mouseX > BeginButton.getPosition().x - BeginButton.getTexture()->getSize().x/2
                        && mouseX < BeginButton.getPosition().x + BeginButton.getTexture()->getSize().x - BeginButton.getTexture()->getSize().x/2
                        && mouseY > BeginButton.getPosition().y - BeginButton.getTexture()->getSize().y / 2
                        && mouseY < BeginButton.getPosition().y + BeginButton.getTexture()->getSize().y -BeginButton.getTexture()->getSize().y / 2) {
                     
                        WelcomeScreenOpen = false;
                        welcomeScreenWindow.close();
                    }
                }
            }
            //if welcome screen not true then this displays main window
            if (!WelcomeScreenOpen) {
                sf::RenderWindow MainWindow(sf::VideoMode(Width, Height), "dsABC's", sf::Style::Close);

                while (MainWindow.isOpen()) {
                    sf::Event event;
                    while (MainWindow.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed) {
                            MainWindow.close();
                        }
                        if (event.type == sf::Event::TextEntered && WelcomeScreenOpen == false) {
                            switch (event.key.code) {
                                //keycode for backspace is 8
                            case 8:
                                if (StringInput[StringInput.size() - 1] != '|' && StringInput.size() == 10) {
                                    //if at max capacity and trying to delete
                                    StringInput.erase(StringInput.begin() + StringInput.size() - 1);
                                    StringInput.append("|");
                                }
                                else if (StringInput.size() == 1) {
                                    //do nothing when no letters have been input yet (don't delete cursor)
                                }
                                else {
                                    //any other circumstance
                                    StringInput.erase(StringInput.begin() + StringInput.size() - 2);
                                }
                                break;
                            default:
                                string temp;
                                if (StringInput.size() < 11) {
                                    if (((event.text.unicode > 64) && (event.text.unicode < 91))
                                        || ((event.text.unicode > 96) && (event.text.unicode < 123))) {
                                        temp += static_cast<char>(event.text.unicode);
                                        if (StringInput.size() == 1) {
                                            string temp2(1, (char)tolower(temp[0]));
                                            StringInput.erase(StringInput.begin() + StringInput.size() - 1);
                                            StringInput.append(temp2);
                                            StringInput.append("|");
                                        }
                                        else if (StringInput.size() == 10) {
                                                string temp2(1, (char)tolower(temp[0]));
                                                StringInput.erase(StringInput.begin() + StringInput.size() - 1);
                                                StringInput.append(temp2);
                                        }
                                        else {
                                            string temp2(1, (char)tolower(temp[0]));
                                            StringInput.erase(StringInput.begin() + StringInput.size() - 1);
                                            StringInput.append(temp2);
                                            StringInput.append("|");
                                        }

                                    }
                                }
                                break;
                            }
                        }
                        if (event.type == sf::Event::MouseButtonPressed) {
                            //Checks for left click
                            if (event.mouseButton.button == sf::Mouse::Left) {
                                //gets current x,y of click
                                auto mouseX = event.mouseButton.x;
                                auto mouseY = event.mouseButton.y;

                                //checks if generate button is pressed
                                if (mouseX > GenerateButton.getPosition().x - GenerateButton.getTexture()->getSize().x / 2
                                    && mouseX < GenerateButton.getPosition().x + GenerateButton.getTexture()->getSize().x - GenerateButton.getTexture()->getSize().x / 2
                                    && mouseY > GenerateButton.getPosition().y - GenerateButton.getTexture()->getSize().y / 2
                                    && mouseY < GenerateButton.getPosition().y + GenerateButton.getTexture()->getSize().y - GenerateButton.getTexture()->getSize().y / 2) {
                                    cout << StringInput.size();
                                    if(StringInput.size() > 0) {
                                        //Read in input string (limit 15 characters as that is the max size of the board, ? entered for wild cards)

                                        //Call generator functions the highest scoring letters are returned as a single string with delimiter '|' used between each word
                                        //please format string like so: "ADDS (6)\t\tDADS (6)\t\tDAGS (6)\t\tGADS (6)" so it can be displayed properly


                                        //Load up dictionary & store for later comparison
                                        Dictionary dictionary;
                                        int size = StringInput.size() - 1;
                                        if (StringInput.at(size) == '|') {
                                            StringInput = StringInput.substr(0, size);
                                        }

                                        set<string> TempGenTest = getHighestWords(StringInput, dictionary);

                                        string StringFormat = "";
                                        Word w;
                                        if(TempGenTest.size() != 0 ) {
                                            int score = w.evaluateWord(*TempGenTest.begin());
                                            // set<string>::iterator itr;
                                            for (auto itr = TempGenTest.begin(); itr != TempGenTest.end(); itr++) {
                                                StringFormat += *itr + " (" + to_string(score) + ")\t\t";
                                            }
                                            //"ADDS (6)\t\tDADS (6)\t\tDAGS (6)\t\tGADS (6)\t\tADDS (6)\t\tDADS (6)\t\tDAGS (6)\t\tGADS (6)";

                                            // Wrap string in box can handle max three lines ish

                                            PossibleWordsText1.setString(StringFormat);
                                            setText(PossibleWordsText1, Width / 2.0f, Height / 2.0f - 150);

                                            //look through each character of string
                                            for (auto i = 0; i < PossibleWordsText1.getString().getSize(); i++) {
                                                if (PossibleWordsText1.findCharacterPos(i).x >=
                                                    (PossibleWords.getPosition().x +
                                                     PossibleWords.getTexture()->getSize().x -
                                                     PossibleWords.getTexture()->getSize().x / 2) - 400) {
                                                    if (i - 1 == '\t') {
                                                        StringFormat.insert(i - 1, "\n\n");
                                                        PossibleWordsText1.setString(StringFormat);
                                                    } else {
                                                        while (StringFormat.at(i - 1) != '\t') {
                                                            i--;
                                                        }
                                                        StringFormat.insert(i, "\n\n");
                                                        PossibleWordsText1.setString(StringFormat);
                                                    }
                                                }
                                            }
                                        } else{
                                            PossibleWordsText1.setString("Draw a Piece, nothing found");
                                        }
                                        setText(PossibleWordsText1, Width / 2.0f + 35, Height / 2.0f - 130);


                                    }
                                    StringInput += "|";
                                }
                               
                            }
                        }

                        MainWindow.clear(sf::Color::White);
                        MainWindow.draw(Background);
                        MainWindow.draw(GenerateButton);
                        MainWindow.draw(PossibleWords);
                        MainWindow.draw(MainScreenInstructionText);
                        MainWindow.draw(TextBox);
                        MainWindow.draw(PossibleWordsText1);

                        sf::Text inputText;
                        inputText.setFont(welcomeScreenFont);
                        inputText.setString(StringInput);
                        inputText.setCharacterSize(40);
                        inputText.setFillColor(sf::Color::Black);
                        inputText.setStyle(sf::Text::Bold);
                        setText(inputText, Width / 2.0f, Height / 2.0f + 195);
                        MainWindow.draw(inputText);
                        MainWindow.display();
                    }
                }
            }
            if (WelcomeScreenOpen) {
                welcomeScreenWindow.clear(sf::Color(245, 90, 90));
                welcomeScreenWindow.draw(welcomeScreenTextLine1);
                welcomeScreenWindow.draw(welcomeScreenTextLine2);
                welcomeScreenWindow.draw(welcomeScreenTextLine3);
                welcomeScreenWindow.draw(welcomeScreenTextLine4);
                welcomeScreenWindow.draw(BeginButton);
                welcomeScreenWindow.display();
            }
        }
    }
    return 0;
}