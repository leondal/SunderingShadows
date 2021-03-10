#include <std.h>
#include <dirs.h>

int do_stuff(string str) {
    tell_player(TP, "Doing stuff.");
    write_file(DIR_BOARDS+"/"+"grendeltest.txt", "This is just a test.");
    tell_player(TP, "Written");
   return 1;
}
