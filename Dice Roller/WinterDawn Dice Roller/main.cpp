#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int diceType = 0;
    int diceNumber = 0;
    int rollNumber = 0;

    std::srand (time(NULL));

    std::cout << std::endl << std::endl << std::endl << "Welcome to the WinterDawn dice roller" << std::endl << std::endl;
    std::cout << "Please enter the number of dice to roll followed by the type of dice";
    if (rollNumber == 0)
    {
        std::cout << " followed by the number of rolls";
    }
    std::cout << std::endl;

    std::cin >> diceNumber >> diceType;
    if (rollNumber == 0)
    {
        std::cin >> rollNumber;
    }

    while (diceNumber != 0 && diceType != 0 && rollNumber !=0)
    {
        std::vector <std::vector <int> > rollResults;
        std::vector <int> numberMoSes;
        int moSesPercent[20] = {};
        int moSesPercentCompoud[20] = {};

        for (int i=0; i < rollNumber; i++)
        {
            std::vector <int> tempDiceResult;

            for (int j = 0; j < diceNumber; j++)
            {
                tempDiceResult.push_back ((rand() % diceType)+1);
            }
            rollResults.push_back(tempDiceResult);
        }

        for (int i = 0; i < rollResults.size(); i++)
        {
            numberMoSes.push_back(0);
            if (rollNumber == 1)
            {
                std::cout << std::endl << "The Dice Rolled ";
            }
            for (int j = 0; j < rollResults[i].size(); j++)
            {
                if (rollNumber == 1)
                {
                    std::cout << rollResults[i][j] << " ";
                }
                numberMoSes[i] += (rollResults[i][j]) / 4;
                if (rollResults[i][j] == 1)
                {
                    numberMoSes[i]--;
                }
            }
            if (rollNumber == 1)
            {
                std::cout << std::endl << "Number of MoSes rolled: " << numberMoSes[i];
            }
            else
            {
                moSesPercent[numberMoSes[i]+9]++;
            }
        }

        for (int i = 0; i < 20; i++)
        {
            for (int j = i; j < 20; j++)
            {
                moSesPercentCompoud[i]+= moSesPercent[j];
            }
        }

        for (int i = 0; i < 20; i++)
        {
            if (moSesPercent[i] != 0)
            {
                std::cout << moSesPercent[i] << " roll(s) obtained " << i - 9;
                if (i == 0)
                {
                    std::cout << " or less";
                }
                if (i == 19)
                {
                    std::cout << " or more";
                }
                std::cout << " MoSess ( " << (float)moSesPercent[i] / (float)rollNumber * 100 << "% )";
                std::cout << "\t-\t";
                std::cout << moSesPercentCompoud[i] << " rolls were over DL " << i - 9 << " ( " << (float)moSesPercentCompoud[i] / (float)rollNumber * 100 << "% )";
                std::cout << std::endl;
            }
        }

        if (rollNumber > 1)
        {
            std::cout << std::endl << "\tNumber of MoSes obtained" << std::endl;
            for (int i = 10; i < 20; i++)
            {
                std::cout << "\t";
                if (i != 0)
                {
                    std::cout << " ";
                }
                if (i == 19)
                {
                    std::cout << " ";
                }
                float tempI = (float)i / 2;
                std::cout << 100 - (10*tempI) << " ┣ ";
                for (int j = 0; j < 20; j++)
                {
                    if (moSesPercent[j] != 0)
                    {
                        if (((float)moSesPercent[j] / (float)rollNumber * 100) >= 100 - (10*tempI))
                        {
                            std::cout << " █ ";
                        }
                        else
                        {
                            if (((float)moSesPercent[j] / (float)rollNumber * 100) >= 99.375 - (10*tempI))
                            {
                                std::cout << " ▇ ";
                            }
                            else
                            {
                                if (((float)moSesPercent[j] / (float)rollNumber * 100) >= 98.75 - (10*tempI))
                                {
                                    std::cout << " ▆ ";
                                }
                                else
                                {
                                    if (((float)moSesPercent[j] / (float)rollNumber * 100) >= 98.125 - (10*tempI))
                                    {
                                        std::cout << " ▅ ";
                                    }
                                    else
                                    {
                                        if (((float)moSesPercent[j] / (float)rollNumber * 100) >= 97.5 - (10*tempI))
                                        {
                                            std::cout << " ▄ ";
                                        }
                                        else
                                        {
                                            if (((float)moSesPercent[j] / (float)rollNumber * 100) >= 96.875 - (10*tempI))
                                            {
                                                std::cout << " ▃ ";
                                            }
                                            else
                                            {
                                                if (((float)moSesPercent[j] / (float)rollNumber * 100) >= 96.25 - (10*tempI))
                                                {
                                                    std::cout << " ▂ ";
                                                }
                                                else
                                                {
                                                    if (((float)moSesPercent[j] / (float)rollNumber * 100) >= 95.625- (10*tempI))
                                                    {
                                                        std::cout << " ▁ ";
                                                    }
                                                    else
                                                    {
                                                        std::cout << "   ";
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                std::cout << std::endl;
            }
            std::cout << "\t    ┗";
            for (int i = 0; i < 20; i++)
            {
                if (moSesPercent[i] != 0)
                {
                    std::cout << "━━┻";
                }
            }
            std::cout << std::endl <<  "\t     ";
            for (int i = 0; i < 20; i++)
            {
                if (moSesPercent[i] != 0)
                {
                    if (i-9 > -1 && i-9 < 10)
                    {
                        std::cout << " ";
                    }
                    std::cout << " " << i-9;
                }
            }

            std::cout << std::endl << std::endl << "\tRolls beating a DL" << std::endl;
            for (int i = 0; i < 20; i++)
            {
                std::cout << "\t";
                if (i != 0)
                {
                    std::cout << " ";
                }
                if (i == 19)
                {
                    std::cout << " ";
                }
                float tempI = (float)i / 2;
                std::cout << 100 - (10*tempI) << " ┣ ";
                for (int j = 0; j < 20; j++)
                {
                    if (moSesPercent[j] != 0)
                    {
                        if (((float)moSesPercentCompoud[j] / (float)rollNumber * 100) >= 100 - (10*tempI))
                        {
                            std::cout << " █ ";
                        }
                        else
                        {
                            if (((float)moSesPercentCompoud[j] / (float)rollNumber * 100) >= 99.375 - (10*tempI))
                            {
                                std::cout << " ▇ ";
                            }
                            else
                            {
                                if (((float)moSesPercentCompoud[j] / (float)rollNumber * 100) >= 98.75 - (10*tempI))
                                {
                                    std::cout << " ▆ ";
                                }
                                else
                                {
                                    if (((float)moSesPercentCompoud[j] / (float)rollNumber * 100) >= 98.125 - (10*tempI))
                                    {
                                        std::cout << " ▅ ";
                                    }
                                    else
                                    {
                                        if (((float)moSesPercentCompoud[j] / (float)rollNumber * 100) >= 97.5 - (10*tempI))
                                        {
                                            std::cout << " ▄ ";
                                        }
                                        else
                                        {
                                            if (((float)moSesPercentCompoud[j] / (float)rollNumber * 100) >= 96.875 - (10*tempI))
                                            {
                                                std::cout << " ▃ ";
                                            }
                                            else
                                            {
                                                if (((float)moSesPercentCompoud[j] / (float)rollNumber * 100) >= 96.25 - (10*tempI))
                                                {
                                                    std::cout << " ▂ ";
                                                }
                                                else
                                                {
                                                    if (((float)moSesPercentCompoud[j] / (float)rollNumber * 100) >= 95.625 - (10*tempI))
                                                    {
                                                        std::cout << " ▁ ";
                                                    }
                                                    else
                                                    {
                                                        std::cout << "   ";
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                std::cout << std::endl;
            }
            std::cout << "\t    ┗";
            for (int i = 0; i < 20; i++)
            {
                if (moSesPercent[i] != 0)
                {
                    std::cout << "━━┻";
                }
            }
            std::cout << std::endl <<  "\t     ";
            for (int i = 0; i < 20; i++)
            {
                if (moSesPercent[i] != 0)
                {
                    if (i-9 > -1 && i-9 < 10)
                    {
                        std::cout << " ";
                    }
                    std::cout << " " << i-9;
                }
            }
        }

        //std::cout << "\t┣ █ █\n\t┣ █ █\n\t┣  █ ";

        diceType = diceNumber = 0;
        std::cout << std::endl << std::endl << "Please enter the number of dice to roll followed by the type of dice" << std::endl;
        std::cin >> diceNumber >> diceType;
    }

    std::cout << std::endl << std::endl << "Thank you." << std::endl << std::endl;

    return 0;
}
