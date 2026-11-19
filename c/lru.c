/*

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists.
Otherwise, add the key-value pair to the cache. If the number of keys exceeds
the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

*/

typedef struct node {
    int value;
    int key;
    struct node *next;
    struct node *prev;
} NODE, *PNODE;

typedef struct {
    int capacity;
    int count;
    PNODE head;
    PNODE tail;
    PNODE hash[10001];
} LRUCache, *PLRUCache;

PLRUCache lRUCacheCreate(int capacity) {
    LRUCache* cache;

    cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->count = 0;

    cache->head = (PNODE)malloc(sizeof(NODE));
    cache->tail = (PNODE)malloc(sizeof(NODE));
    cache->head->next = cache->tail;
    cache->head->prev = NULL;
    cache->tail->prev = cache->head;
    cache->tail->next = NULL;

    for (int i = 0; i < 10001; i++) {
        cache->hash[i] = NULL;
    }

    return cache;
}

void move_to_front(PLRUCache cache, PNODE node) {
    node->next = cache->head->next;
    node->prev = cache->head;

    cache->head->next->prev = node;
    cache->head->next = node;
}

void remove_node(PNODE node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

int lRUCacheGet(PLRUCache cache, int key) {
    PNODE node;

    if (cache->hash[key] == NULL) {
        return -1;
    }

    node = cache->hash[key];
    remove_node(node);
    move_to_front(cache, node);
    return node->value;
}

void lRUCachePut(PLRUCache cache, int key, int value) {
    PNODE node;
    PNODE lru_node;

    if (cache->capacity == 0) {
        return;
    }

    if (cache->hash[key] != NULL) {

        //
        // Node exists.
        //

        node = cache->hash[key];
        node->value = value;
        remove_node(node);
        move_to_front(cache, node);

    } else {

        //
        // New node to add.
        //

        node = (PNODE)malloc(sizeof(NODE));
        node->key = key;
        node->value = value;
        cache->hash[key] = node;
        if (cache->capacity == cache->count) {
            lru_node = cache->tail->prev;
            cache->hash[lru_node->key] = NULL;
            remove_node(lru_node);
            free(lru_node);
            cache->count--;
        }

        move_to_front(cache, node);
        cache->count++;
    }
}

void lRUCacheFree(PLRUCache cache) {
    PNODE curr;
    PNODE next;

    curr = cache->head;
    while(curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }

    free(cache);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/

// ----------------------------------------------------------------------------

struct node {
    int key;
    int val;
    struct node *next;
    struct node *prev;
};

typedef struct {
    int cap;
    int count;
} LRUCache;

struct node *head;
struct node *tail;

struct node* rem[10001];
LRUCache* lRUCacheCreate(int capacity) {

    LRUCache *cache = malloc(sizeof(LRUCache));
    cache->cap = capacity;
    cache->count = 0;
    head = malloc(sizeof(struct node));
    tail = malloc(sizeof(struct node));

    head->next = tail;
    tail->prev = head;

    for (int i = 0; i < 10001; i++)
        rem[i] = NULL;
    
    return cache;
}

void del(struct node *curr) {

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
}

void add(struct node *curr) {

    curr->next = head->next;
    curr->prev = head;
    
    head->next->prev = curr;
    head->next = curr;

}

int lRUCacheGet(LRUCache* obj, int key) {
        if(obj->count == 0)
            return -1;

        if(rem[key] == NULL)
            return -1;

        int val;
        struct node *curr = rem[key];
        val = curr->val;
        del(curr);
        add(curr);
        return val;
}

void lRUCachePut(LRUCache* obj, int key, int value) {

        printf("key=%d\n",key);
        if(rem[key] != NULL) {

        struct node *curr = rem[key];
        curr->val = value;
        del(curr);
        add(curr);
        }
    
        else {

            if(obj->count == obj->cap) {
                obj->count--;
                rem[tail->prev->key] = NULL;
                del(tail->prev);
            }

            obj->count++;
            struct node *curr = malloc(sizeof(struct node));
            curr->val = value;
            curr->key = key;
            printf("curr=%x\n",curr);
            printf("add key=%d val =%d \n",key,value);
            rem[key] = curr;
            add(curr);
        }
  
}

void lRUCacheFree(LRUCache* obj) {
    

    for(int i = 0; i <= 10000; i++)
        if(rem[i])
            free(rem[i]);
    
    free(head);
    free(tail);
    free(obj);

}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/