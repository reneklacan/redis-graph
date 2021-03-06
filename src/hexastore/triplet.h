#ifndef TRIPLET_H
#define TRIPLET_H

#include "../graph/edge.h"
#include "../redismodule.h"
#include "../util/triemap/triemap.h"

#define TRIPLET_ELEMENT_DELIMITER ":"
#define TRIPLET_PREDICATE_DELIMITER "@"

// typedef enum {UNKNOW, O, P, PO, S, SO, SP, SPO} TripletKind;
typedef enum {UNKNOW, P, O, OP, S, SP, SO, SOP} TripletKind;

typedef struct {
	char* subject;
	char* predicate;
	char* object;
	TripletKind kind;
} Triplet;

typedef TrieMapIterator TripletIterator;

// Creates a new triplet
Triplet* NewTriplet(const char *S, const char *P, const char *O);

// Given an edge (A) -[edge]-> (B), creates a new triplet.
Triplet* TripletFromEdge(const Edge *edge);

// Given a node, creates a new triplet.
Triplet* TripletFromNode(const Node *node);

// Creates a new triplet from string.
Triplet* TripletFromString(const char *input);

// Returns a string representation of triplet.
char* TripletToString(const Triplet *triplet);

// Checks if given triplets are the same.
int TripletCompare(const Triplet *A, const Triplet *B);

// Validate checks the triplet for validity and returns false if something is wrong.
int ValidateTriplet(const Triplet *triplet);

// Frees allocated space by given triplet.
void FreeTriplet(Triplet *triplet);

// -------------Triplet cursor-------------

// Returns the next triplet from the cursor.
int TripletIterator_Next(TripletIterator* iterator, Triplet** triplet);

void TripletIterator_Free(TripletIterator *cursor);

#endif