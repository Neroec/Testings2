#include <gtest/gtest.h>

/* using namespace testing; */
extern "C" {
#include "_text.h"
}

TEST(save_positive, correct)
{
    char line1[MAXLINE+1] = {"0Helloy\n"};
    char line2[MAXLINE+1] = {"1Helloy\n"};
    char line3[MAXLINE+1] = {"2Helloy\0"};
    node *nd1; nd1 = (node *) malloc(sizeof(node));
    node *nd2; nd2 = (node *) malloc(sizeof(node));
    node *nd3; nd3 = (node *) malloc(sizeof(node));
    nd1->next = nd2; nd1->previous = NULL; strncpy(nd1->contents, line1, MAXLINE);
    nd2->next = nd3; nd2->previous = nd1; strncpy(nd2->contents, line2, MAXLINE);
    nd3->next = NULL; nd3->previous = nd2; strncpy(nd3->contents, line3, MAXLINE);

    crsr *cur; cur = (crsr *) malloc(sizeof(crsr));
    cur->line = nd1;
    cur->position = 5;

    size_t size = 3;
    text txt; txt = (list *) malloc(sizeof(list));
    txt->length = size;
    txt->begin = nd1;
    txt->end = nd3;
    txt->cursor = cur;

    FILE *file;
    size_t lenght;
    char line[MAXLINE+1] = {"save.txt"};
    
    save(txt, line);
    if ((file = fopen(line, "r")) == NULL) {
        EXPECT_EQ(0, errno);
    }
    
    EXPECT_EQ(fscanf(file, "%s", line), 1);
    lenght = strlen(line);
    line[lenght] = '\n';
    line[lenght + 1] = '\0';
    EXPECT_EQ(strcmp(line, line1), 0);
    
    EXPECT_EQ(fscanf(file, "%s", line), 1);
    lenght = strlen(line);
    line[lenght] = '\n';
    line[lenght + 1] = '\0';
    EXPECT_EQ(strcmp(line, line2), 0);
    
    EXPECT_EQ(fscanf(file, "%s", line), 1);
    EXPECT_EQ(strcmp(line, line3), 0);

    EXPECT_EQ(fscanf(file, "%s", line), EOF);

    free(txt); free(cur); free(nd1); free(nd2); free(nd3);
}

TEST(save_negative, zero_lines)
{
    size_t size = 0;
    text txt; txt = (list *) malloc(sizeof(list));
    txt->length = size;
    txt->begin = NULL;
    txt->end = NULL;
    txt->cursor = NULL;

    FILE *file;
    char line[MAXLINE+1] = {"save.txt"};

    save(txt, line);
    if ((file = fopen(line, "r")) == NULL) {
        EXPECT_EQ(0, errno);
    }
    
    EXPECT_EQ(fscanf(file, "%s", line), EOF);

    free(txt);
}
