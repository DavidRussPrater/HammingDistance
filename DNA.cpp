// David Prater
// 10/7/2015
// Homework #5
// This program compares lines of DNA to determine species


#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;
int main(int argc, char* argv[])
{
	int stringLength;
	int humanHamming;
	int mouseHamming;
	float mouseSimilarity;
	float humanSimilarity;
	string humanDNA;
	string mouseDNA;
	string unknownDNA;

//Open files and convert contents to a string
	ifstream mouseDNAStream;
	mouseDNAStream.open(argv[1]);
	getline(mouseDNAStream, mouseDNA);
	ifstream humanDNAStream;
	humanDNAStream.open(argv[2]);
	getline(humanDNAStream, humanDNA);
	ifstream unknownDNAStream;
	unknownDNAStream.open(argv[3]);
	getline(unknownDNAStream, unknownDNA);
	
//Count characters in each string
	stringLength = humanDNA.length();

	
//Determine amount of disimilar characters

	mouseHamming = 0;
	humanHamming = 0;
	
	for(int i = 0; i < stringLength; i++){
		if (unknownDNA[i] != mouseDNA[i])
		{++mouseHamming;}}
	
	for(int i = 0; i < stringLength; i++){
		if (unknownDNA[i] != humanDNA[i])
		{++humanHamming;}}
	

//Calculate similarity score and match
	mouseSimilarity = (( stringLength - mouseHamming));
	mouseSimilarity=mouseSimilarity/(stringLength);
	humanSimilarity = (( stringLength - humanHamming));
	humanSimilarity=humanSimilarity/(stringLength);
	string match;

	
	if (abs(mouseSimilarity - humanSimilarity) < .0001)
	{
		match = "identity cannot be determined";
	}
	else if (mouseSimilarity > humanSimilarity)
	{
		match = "Mouse";
	}   
	else if (mouseSimilarity < humanSimilarity)
	{
		match = "Human";
	}

	
//Display results to user
	cout << "MouseCompare = " << mouseSimilarity * 100 << " %" << endl;
	cout << "HumanCompare = " << humanSimilarity * 100 << " %" << endl;
	cout << match << endl;
	return 0;
}
