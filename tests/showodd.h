#include <gtest/gtest.h>

/* using namespace testing; */
extern "C" {
#include "text/_text.h"
#include "common.h"
}

TEST(showodd_positive, correct)
{
    char line1[MAXLINE+1] = {"0Helloy\n"};
    char line2[MAXLINE+1] = {"1Helloy\n"};
    char line3[MAXLINE+1] = {"2Helloy\0"};
    node *nd1;
    node *nd2;
    node *nd3;
    nd1 = (node *) malloc(sizeof(node));
    nd2 = (node *) malloc(sizeof(node));
    nd3 = (node *) malloc(sizeof(node));
    nd1->next = nd2; nd1->previous = NULL; strncpy(nd1->contents, line1, MAXLINE);
    nd2->next = nd3; nd2->previous = nd1; strncpy(nd2->contents, line2, MAXLINE);
    nd3->next = NULL; nd3->previous = nd2; strncpy(nd3->contents, line3, MAXLINE);

    crsr *cur;
    cur = (crsr *) malloc(sizeof(crsr));
    cur->line = nd1;
    cur->position = 5;

    size_t size = 3;
    text txt;
    txt = (list *) malloc(sizeof(list));
    txt->length = size;
    txt->begin = nd1;
    txt->end = nd3;
    txt->cursor = cur;

    char line[MAXLINE+1] = {"showodd.txt"};
    showodd(txt, line);
    FILE *file;
    file = fopen(line, "r");
    EXPECT_EQ(fscanf(file, "%s", line), 1);
    size_t lenght = strlen(line);
    line[lenght] = '\n';
    line[lenght + 1] = '\0';
    EXPECT_EQ(strcmp(line, line2), 0);
    EXPECT_EQ(fscanf(file, "%s", line), EOF);

    free(txt);
    free(cur);
    free(nd1);
    free(nd2);
    free(nd3);
}
