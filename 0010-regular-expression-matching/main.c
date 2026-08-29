#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum
{
    TRANSITION_NONE,
    TRANSITION_LITERAL,
    TRANSITION_WILDCARD,
    TRANSITION_EPSILON
} TransitionType;

typedef struct
{
    uint16_t from_state;
    uint16_t to_state;
    TransitionType type;
    char literal;
} Edge;

typedef struct
{
    uint16_t start_state;
    uint16_t accept_state;
    uint16_t state_count;
    Edge *edges;
    uint16_t edge_count;
    uint64_t active_states;
} NFA;

uint64_t activateState(uint64_t activeStates, uint8_t s)
{
    return activeStates | (UINT64_C(1) << s);
}

uint64_t deactivateState(uint64_t activeStates, uint8_t s)
{
    return activeStates & ~(UINT64_C(1) << s);
}

bool isActiveState(uint64_t activeStates, uint8_t s)
{
    return (activeStates & (UINT64_C(1) << s)) != 0;
}

Edge emptyEdge(void)
{
    Edge e;
    e.from_state = 0;
    e.to_state = 0;
    e.literal = '\0';
    e.type = TRANSITION_NONE;
    return e;
}

NFA emptyNFA(void)
{
    NFA n;
    n.start_state = 0;
    n.accept_state = 0;
    n.state_count = 1;
    n.edges = NULL;
    n.edge_count = 0;
    n.active_states = 0b00000001;
    return n;
}

NFA addEdge(NFA n, uint16_t from_state, uint16_t to_state, TransitionType type, char rule)
{
    uint16_t largestState = from_state > to_state ? from_state : to_state;
    if (largestState >= 64)
    {
        fprintf(stderr, "State index exceeds bitset capacity\n");
        free(n.edges);
        exit(EXIT_FAILURE);
    }

    if (largestState >= n.state_count)
        n.state_count = largestState + 1;

    Edge e = emptyEdge();
    e.from_state = from_state;
    e.to_state = to_state;
    e.type = type;
    e.literal = (type == TRANSITION_LITERAL) ? rule : '\0';

    Edge *resized = realloc(n.edges, (n.edge_count + 1) * sizeof(Edge));
    if (resized == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(n.edges);
        exit(EXIT_FAILURE);
    }

    n.edges = resized;
    n.edges[n.edge_count] = e;
    n.edge_count++;

    return n;
}

NFA addLiteral(char literal)
{
    // create empty NFA fragment
    NFA fragment = emptyNFA();

    // add edge with literal rule

    // set literal rule to_state as NFA accept state

    // return NFA fragment
}
NFA addWildcard(void)
{
    // create empty NFA fragment

    // add edge with epsilon transition

    // set literal rule to_state as NFA accept state

    // return NFA fragment
}

NFA addKleeneClosure(NFA fragment)
{
    // modify previous fragment following thompsons construction algorithm

    // set new start state

    // add epsilon transition from new start state to old start state

    // set new end state

    // add epsilon transition from old end state to new end state

    // add epsilon transition from old end state to old start state

    // return altered NFA fragment
}

NFA concatenate(NFA left, NFA right)
{
}

NFA regexToNFA(char *p)
{
    NFA n = emptyNFA();
    for (size_t i = 0; p[i] != '\0'; i++)
    {
        NFA fragment = (p[i] == '.') ? addWildcard()
                                     : addLiteral(p[i]);

        if (p[i + 1] == '*')
        {
            fragment = addKleeneClosure(fragment);
            i++;
        }

        n = concatenate(n, fragment);
    }

    return n;
}

bool isMatch(char *s, char *p)
{
    uint64_t activeStates = 0;
    NFA nfa = regexToNFA(p);
}

int main(int argc, char const *argv[])
{
    printf("Example 1: %s\n", isMatch("aa", "a") ? "true" : "false");
    printf("Example 2: %s\n", isMatch("aa", "a*") ? "true" : "false");
    printf("Example 3: %s\n", isMatch("ab", ".*") ? "true" : "false");
    return 0;
}
