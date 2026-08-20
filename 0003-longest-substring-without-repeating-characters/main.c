#include <stdio.h>

int lengthOfLongestSubstring(char *s)
{
    int last_seen[128] = {0};   // last index+1 of each ASCII char
    int max = 0;
    int left = 0;

    for (int right = 0; s[right]; right++)
    {
        // If char was seen inside the current window, shrink from left.
        if (last_seen[(int)s[right]] > left)
            left = last_seen[(int)s[right]];

        last_seen[(int)s[right]] = right + 1;

        if (right - left + 1 > max)
            max = right - left + 1;
    }

    return max;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", lengthOfLongestSubstring("Kyqcp20uDnCpl3kfPj0ixriSPvdWKaaVDjS2pza3L8YIncFdLnH7QBBmdyrbJBqt6MyAB8n2ymebVTIySkRo77HXRstiK0VC8jgvWHMTxxJVSvnGVvS5oII8KAePlZmMKXMExp01Ad7btDI7DTZVdkyWVJzL3PY9bfZiMyDbfslvOUW0FgliRFEuhffkCiaVCKZsK9pGeK1grzxoq5vQfJtVTQt6WuccAl3bmIMFq9bUiJknYvEPaCmu9mXFuf6laWoEfDRmFNIXbXO70Ep64W7cEz9r7xA0k0IBBLgmRkh9Fp7yxej3qupHPfiVaEX3JaymrCpkyo8cxzWTCGmSvEw9kBK1mVCChggT5EsbEROoBvHxrwrddb0SyVBGKsNzZvEGcLeUHgtoIXbtmmeYp06bN9sryELuv3dTbNEaLEZ0uqemITDS607iwlp5gTEBROODLb94IBO42mbCO1pbz1cWYopFA5eLNsdiCRiSFpGyQcN7sTCqVlLbwxXRzrYiWLmHtlfpQnRPXrgBjmidQaam8UMUG5ir0ZO0lSZwJXceZydewW2LqqRRnDQEsBjByKqowTYf6ZjamKykHwhyqsTpRu10axCiPkeP1ivBlFikqYx6uuizem8lPVeEdUZ5iOOXbGc1lsws7y1w8Ij66QhTwoxnb4pAK19bbD8ExwaQaaHedUgfgm4s51IIeTsBhbJUOWRVe9QXSlyE4JhhxZOLj3to9dmcnoQ9VdWsFQ8jofkffFBdmud1U8NJ2YcSHIl9kiN2ZKvdZ4zNdmeHXOulGp3xCNQsDpiOGe8I50IYUUrvEvQpomkrLwn3f9Xxp6ZsYgaW2xQ4zqwsM7FVp2"));
    return 0;
}
