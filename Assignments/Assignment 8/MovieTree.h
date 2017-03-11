#ifndef MOVIETREE_H
#define MOVIETREE_H

struct MovieNode{
    int ranking;
    std::string title;
    int year;
    int quantity;
    MovieNode *parent;
    MovieNode *leftChild;
    MovieNode *rightChild;

    MovieNode(){};

    MovieNode(int in_ranking, std::string in_title, int in_year, int in_quantity)
    {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

};

class MovieTree
{

    public:
        MovieTree();
        ~MovieTree();
        void printMovieInventory();
        int countMovieNodes();
        void deleteMovieNode(std::string title);
        void addMovieNode(int ranking, std::string title, int releaseYear, int quantity);
        void findMovie(std::string title);
        void rentMovie(std::string title);

    protected:

    private:
        void DeleteAll(MovieNode * node); //use this for the post-order traversal deletion of the tree
        void printMovieInventory(MovieNode * node);
        void countMovieNodes(MovieNode *node, int *c);
        MovieNode* search(std::string title);
        MovieNode* searchRecursive(MovieNode *node, std::string value);
        MovieNode* treeMinimum(MovieNode *node);
        MovieNode *root;
};

#endif // MOVIETREE_H
