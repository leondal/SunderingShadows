#include <std.h>

#define FORTUNEFILE "/d/common/text/fortunes"

int cmd_fortune()
{
    string * fortunes;

    fortunes = explode(read_file(FORTUNEFILE),"\n");
    write("%^BLUE%^"+fortunes[random(sizeof(fortunes))]);

    return 1;
}

void help()
{
    write("%^BLUE%^You do need help, don't you?%^RESET%^");
}
