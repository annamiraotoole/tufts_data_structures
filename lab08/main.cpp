/*
 * imageEngine
 *
 *     Created on:  Mar 29, 2015
 *         Author:  Chris Gregg
 *  Re-written by:  Mark A. Sheldon, Fall 2016
 *                  Factored out argument collection and image transformation.
 */

#include <iostream>
#include <cctype>

#include "ImageEngine.h"

using namespace std;

struct Arguments {
        string infilename;
        string outfilename;
        char   command;
        int    scaleFactor;
};

Arguments getArguments();
void      performTransform(char command,
                           int scaleFactor,
                           ImageEngine &imageEng);

int main()
{
        Arguments   args = getArguments();
	ImageEngine imageEng;

	imageEng.readImage(args.infilename);
	cout << "Done reading image.\n";

        performTransform(args.command, args.scaleFactor, imageEng);

	imageEng.save(args.outfilename);

	cout << "To see your new image, type the following:\n";
	cout << "  eog " << args.outfilename << "\n";

	return 0;
}

Arguments getArguments()
{
        Arguments args = {"", "", '?', 0};

	cout << "Filename: ";
	cin  >> args.infilename;

	cout << "Scale up or down, mirror,\n";
	cout << "flip, or psychedelic? (u/d/m/f/p): ";
	cin  >> args.command;
	args.command = tolower(args.command);

	if (args.command == 'u' or args.command == 'd') {
		cout << "Scale factor: ";
		cin  >> args.scaleFactor;
	}
	cout << "Filename for save? ";
	cin  >> args.outfilename;

        return args;
}

void performTransform(char command, int scaleFactor, ImageEngine &imageEng)
{
	switch (command) {
	case 'u':
		imageEng.scale_up(scaleFactor);
		break;
	case 'd':
		imageEng.scale_down(scaleFactor);
		break;
	case 'm':
		imageEng.mirror();
		break;
	case 'f':
		imageEng.flip();
		break;
	case 'p':
		imageEng.psychedelic();
		break;
	default:
		cerr << "Not a recognized command:  " << command << endl;;
	}
}
