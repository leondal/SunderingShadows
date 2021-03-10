#include <std.h>

int cmd_man(string str)
{
    int columns, scrwidth;

    scrwidth = atoi(TP->getenv("SCREEN"));
    columns = atoi(TP->getenv("COLUMNS"));

    if (!str) {
        write("%^BOLD%^Sections: ");
        write(auto_format_page(get_dir("/doc/efun/"), TP));
        write("%^BOLD%^To view section type: <man *SECTION>");
        return 1;
    }
    if (regexp(str, "\\*[a-z]+")) {
        string sname;
        sscanf(str, "*%s", sname);
        write("%^BOLD%^Subtopics: ");
        write(auto_format_page(get_dir("/doc/efun/" + sname + "/"), TP));
        write("%^BOLD%^To view topic type: <man *TOPIC>");
        return 1;
    }

    if (regexp(str, "[a-z _]+")) {
        string dir, * dirs;
        string* contents;

        str = replace_string(str, " ", "_");
        dirs = get_dir("/doc/efun/");
        foreach(dir in dirs)
        {
            contents = get_dir("/doc/efun/" + dir + "/");
            if (!sizeof(contents)) {
                continue;
            }
            contents = regexp(contents, "^" + str);
            if (sizeof(contents)) {
                TP->more("/doc/efun/" + dir + "/" + contents[0]);
                return 1;
            }
        }

        write("No such topic.");
        return 1;
    }

    return 1;
}

help()
{
    write("
%^CYAN%^NAME%^RESET%^

man - display efun help

%^CYAN%^SYNTAX%^RESET%^

man [*%^ORANGE%^%^ULINE%^SECTION%^RESET%^|%^ORANGE%^%^ULINE%^TOPIC%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

Man command displays emulated functions manual files. These helpfiles are located in /doc/lib/efuns/ , but to browse them quickly you can use this command.

Without an argument man will display list of all sections.

With *%^ORANGE%^%^ULINE%^SECTION%^RESET%^ argument it will display functions of that section. E.g. %^ORANGE%^<man *arrays>%^RESET%^.

With %^ORANGE%^%^ULINE%^TOPIC%^RESET%^ argument it will display function manual file. E.g. %^ORANGE%^<man filter array>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

more, cd, ls, /adm/simul_efun/, on-site autodocs
");
}
