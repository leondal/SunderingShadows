#include <std.h>

inherit DAEMON;

#define PATH1 "/d/magic/spellbook/save_books/"
#define PATH2 "/d/magic/spellbook/backup_books/"

string *files1,*files2;

void clean_books(string *files,string path)
{
    int i,num;
    string name,file;

    for(i=0;i<sizeof(files);i++)
    {
        file = files[i];
        num = strsrch(file,"_");
        name = file[0..(num-1)];
        if(lower_case(name) == "stefano" || lower_case(name) == "raelith") { continue; }
        if(!user_exists(name)) 
        { 
            tell_object(TP,"Cleaning books... "+name);
            rm(path+file);
        }
    }
    return;
}

int cmd_clean_spellbooks(string str)
{
    files1 = get_dir(PATH1);
    files2 = get_dir(PATH2);

    if(!pointerp(files1)) { return 0; }
    if(!pointerp(files2)) { return 0; }

    clean_books(files1,PATH1);
    clean_books(files2,PATH2);
    return 1;
}
