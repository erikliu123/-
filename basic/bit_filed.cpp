#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct IOdev {
    unsigned R_W: 1; 
    unsigned Dirn: 8; 
    unsigned mode: 3;
};


struct node {
    int data;
struct node *next;
};


#ifdef EBUG
#define DEBUG(m) \
    printf("debug: %s at line %d in file %s\n”, \
    (m), __LINE__, __FILE__)
#else
#define DEBUG(m) /* null statement */
#endif

int main()
{
    IOdev s={1,126,2};
    cout<<sizeof(s)<<endl;

    while ( ! feof(stdin) ) {//ctrl + z结束
        int num;
        int nread = fscanf(stdin, "%d", &num); if (nread <= 0) 
        break;
        fprintf(stdout, "num: %d\n", num);
    }
    /*linked list*/
    struct node n; 
    n.data = 0;
    n.next = NULL;
    return 0;
}

struct List *addToEnd(struct List *listp, struct List *newp) {
    struct List *p;
    if (listp == NULL)
    return newp;
    for (p = listp; p->next != NULL; p = p->next)
    ; /* null statement */
    p->next = newp;
    return listp;
}