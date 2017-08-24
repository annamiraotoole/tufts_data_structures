// Comp 15, Project 2 Part 2

// Annamira O'Toole 11/17/16

// FSTreeTraversal

#include "FSTree.h"
#include "DirNode.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void PrintPaths(string directoryName);
void recursivePrintPaths(DirNode *folder, string str);

int main(int argc, char *argv[]) {

    if (argc != 2){
        exit(1);
    }

    PrintPaths(argv[1]); //??????????

    return 0;

}

void PrintPaths(string directoryName){
    
    FSTree tree = FSTree(directoryName);
    
    recursivePrintPaths(tree.getRoot(), directoryName);

}

// uses pre order tree traversal 
void recursivePrintPaths(DirNode *folder, string str){

    // process node: prints final path/strings for files in node
    int num = folder->numFiles();
    if (num > 0){

        for (int i = 0; i < num; i++){
            cout << str + "/" + folder->getFile(i) << endl;
        }
    }

    // process other nodes within passed in "folder"
    int numOfSubDirs = folder->numSubDirs();

    if (numOfSubDirs > 0){

        for (int j = 0; j < numOfSubDirs; j++){
            DirNode* dir = folder->getSubDir(j);
            recursivePrintPaths(dir, str + "/" + dir->getName());

        }
    }

}

