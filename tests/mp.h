#include <gtest/gtest.h>


/* using namespace testing; */
extern "C" {
#include "_text.h"
}

TEST(mp_positive, correct_arg)
{
    char line1[MAXLINE+1] = {"Helloy\n"};
    char line2[MAXLINE+1] = {"Helloy\0"};
    node *nd1; nd1 = (node *) malloc(sizeof(node));
    node *nd2; nd2 = (node *) malloc(sizeof(node));
    nd1->next = nd2; nd1->previous = NULL; strncpy(nd1->contents, line1, MAXLINE);
    nd2->next = NULL; nd2->previous = nd1; strncpy(nd2->contents, line2, MAXLINE);

    crsr *cur; cur = (crsr *) malloc(sizeof(crsr));
    cur->line = nd2;
    cur->position = 0;

    size_t size = 2;
    text txt; txt = (list *) malloc(sizeof(list));
    txt->length = size;
    txt->begin = nd1;
    txt->end = nd2;
    txt->cursor = cur;

    EXPECT_EQ(mp(txt, 3), 0);
    EXPECT_EQ(txt->cursor->position, 3);

    free(txt); free(cur); free(nd1); free(nd2);
}

TEST(mp_negative, arg_less)
{
    char line[MAXLINE+1] = {"Helloy\0"};
    node *nd; nd = (node *) malloc(sizeof(node));
    nd->next = NULL; nd->previous = NULL; strncpy(nd->contents, line, MAXLINE);

    crsr *cur; cur = (crsr *) malloc(sizeof(crsr));
    cur->line = nd;
    cur->position = 5;

    size_t size = 1;
    text txt; txt = (list *) malloc(sizeof(list));
    txt->length = size;
    txt->begin = nd;
    txt->end = nd;
    txt->cursor = cur;

    EXPECT_EQ(mp(txt, -1), 1);

    free(txt); free(cur); free(nd);
}

TEST(mp_negative, arg_more)
{
    char line[MAXLINE+1] = {"Helloy\0"};
    node *nd; nd = (node *) malloc(sizeof(node));
    nd->next = NULL; nd->previous = NULL; strncpy(nd->contents, line, MAXLINE);

    crsr *cur; cur = (crsr *) malloc(sizeof(crsr));
    cur->line = nd;
    cur->position = 5;

    size_t size = 1;
    text txt; txt = (list *) malloc(sizeof(list));
    txt->length = size;
    txt->begin = nd;
    txt->end = nd;
    txt->cursor = cur;

    EXPECT_EQ(mp(txt, 7), 2);

    free(txt); free(cur); free(nd);
}

TEST(mp_negative, zero_lines)
{
    size_t size = 0;
    text txt; txt = (list *) malloc(sizeof(list));
    txt->length = size;
    txt->begin = NULL;
    txt->end = NULL;
    txt->cursor = NULL;
    
    EXPECT_EQ(mp(txt, 0), 3);

    free(txt);
}

TEST(mp_negative, zero_line1)
{
    char line[MAXLINE+1] = {"\0"};
    node *nd; nd = (node *) malloc(sizeof(node));
    nd->next = NULL; nd->previous = NULL; strncpy(nd->contents, line, MAXLINE);

    crsr *cur; cur = (crsr *) malloc(sizeof(crsr));
    cur->line = nd;
    cur->position = 0;

    size_t size = 1;
    text txt; txt = (list *) malloc(sizeof(list));
    txt->length = size;
    txt->begin = nd;
    txt->end = nd;
    txt->cursor = cur;

    EXPECT_EQ(mp(txt, 0), 4);

    free(txt); free(cur); free(nd);
}

TEST(mp_negative, zero_line2)
{
    char line[MAXLINE+1] = {"\n"};
    node *nd; nd = (node *) malloc(sizeof(node));
    nd->next = NULL; nd->previous = NULL; strncpy(nd->contents, line, MAXLINE);

    crsr *cur; cur = (crsr *) malloc(sizeof(crsr));
    cur->line = nd;
    cur->position = 0;

    size_t size = 1;
    text txt; txt = (list *) malloc(sizeof(list));
    txt->length = size;
    txt->begin = nd;
    txt->end = nd;
    txt->cursor = cur;

    EXPECT_EQ(mp(txt, 0), 0);
    EXPECT_EQ(txt->cursor->position, 0);

    free(txt); free(cur); free(nd);
}
