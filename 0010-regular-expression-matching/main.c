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

bool isMatch(char *s, char *p)
{
    uint64_t activeStates = 0;
    
}

int main(int argc, char const *argv[])
{
    printf("Example 1: %s\n", isMatch("aa", "a") ? "true" : "false");
    printf("Example 2: %s\n", isMatch("aa", "a*") ? "true" : "false");
    printf("Example 3: %s\n", isMatch("ab", ".*") ? "true" : "false");
    return 0;
}
