// this efun will return all of the directories contained in
// the directory specified, ignoring things that are files

#include <std.h>
#include <config.h>

/**
 * this efun will return all of the directories contained in the
 * directory specified, ignoring things that are files
 */
string *get_dirs(string path)
{
    string *files,*dirs=({}), last;
    int i;

    if(!strlen(path)) { return ({}); }

    last = path[(strlen(path)-1)..(strlen(path))];
    if(last != "/") { path = path + "/"; }

    files = get_dir(path);
    if(!files || !pointerp(files) || !sizeof(files)) { return ({}); }

    for(i=0;sizeof(files),i<sizeof(files);i++)
    {
        if(file_size(path+files[i]) == -2) { dirs += ({ files[i] }); }
    }

    return dirs;
}
