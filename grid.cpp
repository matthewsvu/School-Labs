#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

ifstream inFile("input.txt");
ifstream dict("dictionary.txt");
ofstream out("output.txt");

int main(){
    string word;
    char c;
    char grid[9][9] = {};
    int row = 0;
    int column = 0;
    vector<string> wordsFound;
    clock_t start;
    double duration;
    vector<string> words;
    vector<vector<int> > locations;
    //store words from dictionary into vector
    while (getline(dict, word))
    {
        words.push_back(word);
    }
    start = clock();
    //store grid in a c-array
    while (inFile.get(c))
    {
        if (c != ' ' && c != '\n')
        {
            grid[row][column] = c;
            if (column == 8)
            {
                column = 0;
                row++;
            }else
            {
                column++;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "Time it took to populate grid (seconds) : " << duration << endl;
    start = clock();
    //for each character in grid
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            //cout << grid[i][j] << " ";
            //for each word
            for (int k = 0; k < words.size(); k++)
            {
                //check if grid letter equals the first letter of word
                if (grid[i][j] == words[k][0])
                {
                    //check horizontal vertical and diagonal
                    for (int l = 1; l <= words[k].size(); l++)
                    {
                        if (
                            //break if no word was found
                            grid[i-l][j] != words[k][l] &&
                            grid[i+l][j] != words[k][l] &&
                            grid[i][j+l] != words[k][l] &&
                            grid[i][j-l] != words[k][l] &&
                            grid[i+l][j+l] != words[k][l] &&
                            grid[i-l][j-l] != words[k][l] &&
                            grid[i+l][j-l] != words[k][l] &&
                            grid[i-l][j+l] != words[k][l] )
                        {
                            break;
                        }
                        else if (l == words[k].size()-1)
                        {
                            //else write word found to file
                            //out << words[k] << " was found at [" <<
                            //j+1 << "][" << i+1 << "]" << endl;
                            //add word location to locations
                            vector<int> location;
                            location.push_back(j+1);
                            location.push_back(i+1);
                            locations.push_back(location);
                            //add word to wordsFound
                            wordsFound.push_back(words[k]);
                        }
                    }
                }
            }
        }
        //cout << endl;
    }
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "Time it took to finish wordsearch puzzle (seconds) : " << duration << endl;

    out << "number of words found: " << wordsFound.size() << endl;

    for (int i = 0; i < wordsFound.size(); i++){
        out << wordsFound[i] << " was found at [" << locations[i][0] << "][" << locations[i][1] << "]" << endl;
    }
    out << "number of words not found: " << words.size() - wordsFound.size() << endl;

    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < wordsFound.size(); j++) {
            //loop to check if word in dictionary wasn't found and append to output.txt
            if (words[i] == wordsFound[j]){
                break;
            }
            else if (j == wordsFound.size()-1){
                out << words[i] << " was not found!" << endl;
            }
        }
    }
    return 0;
}
