/*
 ============================================================================
 Name         : skipList.h
 Author        : Tim Budd
 Description : Skip List Data Structure Header File
 ============================================================================
 */

#ifndef SKIPLIST_H_
#define SKIPLIST_H_

#ifndef TYPE
#define TYPE double
#endif

#ifndef EQ
#define EQ(a, b) (a == b)
#endif

#ifndef LT
#define LT(a, b) (a < b)
#endif

struct skipLink{
	TYPE value;
	struct skipLink * next;
	struct skipLink * down;
};

struct skipList{
	struct skipLink * topSentinel;
	int size;
};

/* the public interface */
void test(void);
void initSkipList(struct skipList *slst);
int containsSkipList(struct skipList *slst, TYPE e);
void removeSkipList(struct skipList *slst, TYPE e);
void addSkipList(struct skipList *slst, TYPE e);
int sizeSkipList(struct skipList *slst);
void printSkipList(struct skipList *slst);
void mergeSkipList(struct skipList *slst1, struct skipList *slst2);

/* internal routines */
int flipSkipLink();
struct skipLink * slideRightSkipList(struct skipLink * current, TYPE e);
struct skipLink * skipLinkAdd(struct skipLink * current, TYPE e);
struct skipLink * newSkipLink(TYPE e, struct skipLink * nextLnk, struct skipLink* downLnk);

#endif /* SKIPLIST_H_ */
