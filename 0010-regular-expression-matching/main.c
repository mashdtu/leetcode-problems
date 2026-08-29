#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum
{
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

NFA addLiteral(char literal)
{
}
NFA addWildcard(void)
{
}
NFA addKleeneClosure(NFA fragment)
{
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
