//
//  main.c
//  ReverseDoubleLinkedList
//
//  Created by chenyufeng on 16/2/27.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  实现对双向非循环链表的逆序打印
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
typedef struct NodeList{

    int element;
    struct NodeList *prior;
    struct NodeList *next;
}Node;

//初始化非循环双向链表
void initList(Node *pNode){

    pNode = NULL;
    printf("%s函数执行，链表初始化完成\n",__FUNCTION__);
}

//打印非循环双向链表,这个其实是正向打印
void printList(Node *pNode){
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，打印失败\n",__FUNCTION__);
    }else{
        while (pNode != NULL) {
            printf("%d ",pNode->element);
            pNode = pNode->next;
        }
        printf("\n");
    }
}

//创建非循环双向链表
Node *createList(Node *pNode){

    Node *pInsert;
    Node *pMove;
    pInsert = (Node*)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;
    pInsert->prior = NULL;

    scanf("%d",&(pInsert->element));
    pMove = pNode;

    if (pInsert->element <= 0) {

        printf("%s函数执行，输入数据非法，建立链表停止\n",__FUNCTION__);
        return NULL;
    }

    while (pInsert->element > 0) {

        if (pNode == NULL) {
            //构造第一个节点
            pNode = pInsert;
            pMove = pNode;
        }else{

            //链接前后指针
            pMove->next = pInsert;
            pInsert->prior = pMove;
            pMove = pMove->next;
        }

        //为一个新节点分配空间
        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;
        pInsert->prior = NULL;
        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行，建立链表成功\n",__FUNCTION__);
    
    return pNode;
}

//逆序打印双向非循环链表
void ReversePrintList(Node *pNode){

    Node *pMove;
    pMove = pNode;

    if (pNode == NULL) {
        printf("%s函数执行，双向非循环链表为空，逆序打印失败\n",__FUNCTION__);
    }else{
        //从前往后遍历到最后一个节点
        while (pMove->next != NULL) {
            pMove = pMove->next;
        }

        //从后往前遍历到第一个节点，同时打印节点值
        while (pMove != NULL) {

            printf("%d ",pMove->element);
            pMove = pMove->prior;
        }
        printf("\n%s函数执行，双向非循环链表逆序打印成功\n",__FUNCTION__);
    }
}


int main(int argc, const char * argv[]) {

    Node *pList;

    initList(pList);
    printList(pList);

    pList = createList(pList);
    printList(pList);

    ReversePrintList(pList);

    return 0;
}
