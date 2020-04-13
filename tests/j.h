#include <gtest/gtest.h>

/* using namespace testing; */
extern "C" {
#include "text/_text.h"
}

TEST(j_positive, no_next_line_after_next)
{
    char line1[MAXLINE+1] = {"Helloy\n"};
    char line2[MAXLINE+1] = {"Helloy\0"};
    node *nd1;
    node *nd2;
    nd1 = (node *) malloc(sizeof(node));
    nd2 = (node *) malloc(sizeof(node));
    nd1->next = nd2; nd1->previous = NULL; strncpy(nd1->contents, line1, MAXLINE);
    nd2->next = NULL; nd2->previous = nd1; strncpy(nd2->contents, line2, MAXLINE);

    crsr *cur;
    cur = (crsr *) malloc(sizeof(crsr));
    cur->line = nd1;
    cur->position = 5;

    size_t size = 2;
    text txt;
    txt = (list *) malloc(sizeof(list));
    txt->length = size;
    txt->begin = nd1;
    txt->end = nd2;
    txt->cursor = cur;

    EXPECT_EQ(j(txt), 0);
    EXPECT_EQ(strcmp(nd1->contents, "Helloy Helloy\0"), 0);
    EXPECT_EQ(nd1->next, (node*) NULL);
    EXPECT_EQ(txt->end, nd1);

    free(txt);
    free(cur);
    free(nd1);
}

TEST(j_positive, line_after_next)
{
    char line1[MAXLINE+1] = {"Helloy\n"};
    char line2[MAXLINE+1] = {"Helloy\0"};
    node *nd1;
    node *nd2;
    node *nd3;
    nd1 = (node *) malloc(sizeof(node));
    nd2 = (node *) malloc(sizeof(node));
    nd3 = (node *) malloc(sizeof(node));
    nd1->next = nd2; nd1->previous = NULL; strncpy(nd1->contents, line1, MAXLINE);
    nd2->next = nd3; nd2->previous = nd1; strncpy(nd2->contents, line1, MAXLINE);
    nd3->next = NULL; nd3->previous = nd2; strncpy(nd3->contents, line2, MAXLINE);

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

    EXPECT_EQ(j(txt), 0);
    EXPECT_EQ(strcmp(nd1->contents, "Helloy Helloy\n"), 0);
    EXPECT_EQ(nd1->next, nd3);
    EXPECT_EQ(nd3->previous, nd1);

    free(txt);
    free(cur);
    free(nd1);
    free(nd3);
}

TEST(j_negative, last_line)
{
    char line[MAXLINE+1] = {"Helloy\0"};
    node *nd;
    nd = (node *) malloc(sizeof(node));
    nd->next = NULL; nd->previous = NULL; strncpy(nd->contents, line, MAXLINE);

    crsr *cur;
    cur = (crsr *) malloc(sizeof(crsr));
    cur->line = nd;
    cur->position = 5;

    size_t size = 1;
    text txt;
    txt = (list *) malloc(sizeof(list));
    txt->length = size;
    txt->begin = nd;
    txt->end = nd;
    txt->cursor = cur;

    EXPECT_EQ(j(txt), 1);

    free(txt);
    free(cur);
    free(nd);
}
