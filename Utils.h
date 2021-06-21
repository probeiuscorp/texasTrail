#ifndef TEXAS_TRAIL_UTILS_H
#define TEXAS_TRAIL_UTILS_H
#include "DialoguePrompt.h"
#include <string>
#include <vector>
#include <cctype>
#include <math.h>
using std::string;
using std::vector;

class Utils {
    public:
        using StringList = DialoguePrompt::StringList;

    public:
        Utils(){};
        ~Utils(){};

        static string formatAsCurrency(double dbl);
        static string formatAsWeight(double dbl);
        static string numerateString(string str, int count);
        static string stringifyAndRound(double dbl, int round);
        static string toLower(string str);
        static string toUpper(string str);
        static vector<string> split(string str, char delimeter);
        static bool chance(double chance);
        static void awaitEnterKey();

        static StringList centerText(StringList stringList, int width, int height);
        static StringList centerTextAndWrap(string str, int width, int height);
        static double min(int n, ...);
        static double max(int n, ...);

        // template <class T> static inline void randomReorder(vector<T>* list) {
        //     vector<T>* list2 = new vector<T>();
        //     int len = list->size();
        //     list2->reserve(len);
        //     while(len > 0) {
        //         int index = rand()%len;
        //         printf("%d\n", index);
        //         for(int i=0;i<len;i++) {
        //             if((*list)[i] != nullptr) {
        //                 if(index <= 0) {
        //                     list2->push_back((*list)[i]);
        //                     (*list)[i] = nullptr;
        //                     break;
        //                 } else index--;
        //             }
        //         }
        //         len--;
        //     }
        //     list->swap(*list2);
        //     printf("-----\n");
        // }
};

#endif