#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void expand(char *s, __uint16_t len, __int16_t *l, __int16_t *r)
{
    while (*l >= 0 && *r < len && s[*l] == s[*r])
    {
        (*l)--;
        (*r)++;
    }
}

char *longestPalindrome(char *s)
{
    __uint16_t len = strlen(s);
    if (len == 0)
        return "";
    if (len == 1)
        return s;

    __uint16_t best_start = 0, best_len = 1;

    for (__uint16_t i = 0; i <= len - 1; i++)
    {
        __int16_t l = i, r = i;
        expand(s, len, &l, &r);
        if (r - l - 1 > best_len)
        {
            best_start = l + 1;
            best_len = r - l - 1;
        }

        l = i;
        r = i + 1;
        expand(s, len, &l, &r);
        if (r - l - 1 > best_len)
        {
            best_start = l + 1;
            best_len = r - l - 1;
        }
    }

    char *result = malloc(best_len + 1);
    memcpy(result, s + best_start, best_len);
    result[best_len] = '\0';
    return result;
}

int main(int argc, char const *argv[])
{
    printf("babad: %s\n", longestPalindrome("babad"));
    printf("cbbd: %s\n", longestPalindrome("cbbd"));
    printf("long: %s\n", longestPalindrome("jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel"));
    printf("long2: %s\n", longestPalindrome("wsgdzojcrxtfqcfkhhcuxxnbwtxzkkeunmpdsqfvgfjhusholnwrhmzexhfqppatkexuzdllrbaxygmovqwfvmmbvuuctcwxhrmepxmnxlxdkyzfsqypuroxdczuilbjypnirljxfgpuhhgusflhalorkcvqfknnkqyprxlwmakqszsdqnfovptsgbppvejvukbxaybccxzeqcjhmnexlaafmycwopxntuisxcitxdbarsicvwrvjmxsapmhbbnuivzhkgcrshokkioagwidhmfzjwwywastecjsolxmhfnmgommkoimiwlgwxxdsxhuwwjhpxxgmeuzhdzmuqhmhnfwwokgvwsznfcoxbferdonrexzanpymxtfojodcfydedlxmxeffhwjeegqnagoqlwwdctbqnuxngrgovrjesrkjrfjawknbrsfywljscfvnjhczhyeoyzrtbkvvfvofykkwoiclgxyaddhpdoztdhcbauaagjmfzkkdqexkczfsztckdlujgqzjyuittnudpldjvsbwbzcsazjpxrwfafievenvuetzcxynnmskoytgznvqdlkhaowjtetveahpjguiowkiuvikwewmgxhgfjuzkgrkqhmxxavbriftadtogmhlatczusxkktcsyrnwjbeshifzbykqibghmmvecwwtwdcscikyzyiqlgwzycptlxiwfaigyhrlgtjocvajcnqyenxrnjgogeqtvkxllxpuoxargzgcsfwavwbnktchwjebvwwhfghqkcjhuhuqwcdsixrkfjxuzvhjxlyoxswdlwfytgbtqbeimzzogzrlovcdpseoafuxfmrhdswwictsctawjanvoafvzqanvhaohgndbsxlzuymvfflyswnkvpsvqezekeidadatsymbvgwobdrixisknqpehddjrsntkqpsfxictqbnedjmsveurvrtvpvzbengdijkfcogpcrvwyf"));
    return 0;
}
