#include <std.h>

inherit DAEMON;

int cmd_grep(string str) {
    mapping borg;
    string *lines, *files;
    string output, exp, file, tmp;
    int i, max;

    notify_fail("Correct syntax: <grep '[pattern]' [file] (> [output])>\n");
    if(!str) return 0;

    if(sscanf(str, "%s > %s", tmp, output) == 2) {
        if(output[0] != '/')
            output = (string)previous_object()->get_path()+"/"+output;
        str = tmp;
    } else {
        output = 0;
    }

    if(sscanf(str, "'%s' %s", exp, file) != 2 && sscanf(str, "%s %s", exp, file) != 2) {
        return 0;
    }

    if( !(max = sizeof(files = (string *)previous_object()->wild_card(file))) ) {
        message("system", "File not found.", this_player());
        return 1;
    }

    seteuid(getuid(previous_object()));
    for(i=0, borg = ([]); i<max; i++)
    {
        if( file_size(files[i]) == -2){  //If its a directory  all directories have a size of -2.
            continue;
        }
        if( file_size(files[i]) == 0 ) {
            write("%^BOLD%^%^RED%^"+files[i]+" Empty file.");
            continue;
        }
        if( file_size(files[i]) == -1 ) {
            write("%^BOLD%^%^RED%^"+files[i]+" Access Denied.");
            continue;
        }
        {
            string *foundlines;
            string bytes;
            int cbytes = 0;
            int j;
            foundlines=({});
            while((bytes = read_bytes(files[i],cbytes,1024)) &&
                cbytes < 20971520)
            {
                foundlines = regexp(explode(bytes+read_bytes(files[i],cbytes,1), "\n"), exp);
                if(sizeof(foundlines))
                    for(j=0; j< (sizeof(foundlines));j++)
                    {
                        tell_object(TP,"%^BOLD%^%^RED%^"+files[i]+":%^RESET%^"+foundlines[j]);
                    }
                cbytes+=1024;
            }
        }
    }
  
    seteuid(getuid());
    return 1;
}

void help() {
    message("help",
            "Syntax: <grep '[pattern]' [file] (> [redirect])>\n\n"
            "Searches a file or group of files for a specific pattern.  "
            "If the pattern is a single word, then no '' is needed.  Patterns "
            "of more than one word however, need to be enclosed in ''.  "
            "You may redirect the output of the grep to to a file using the >."
            "\n\nSee also: cd, ls, mv, pwd, rm", this_player()
        );
}
