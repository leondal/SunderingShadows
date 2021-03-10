/*
// Thanks to Huthar for this!
// Bug in "here" option fixed by Pallando 93-05-26
// "cwd" option added by Pallando 93-05-30
*/
/**
 * @file
 */

/**
 * Resolves relative path into absolute
 *
 * @param curr Directory to resolve from. Defaults to current directory of this_player().
 * @param tet Relative path string. Defaults to "."
 * @return Absolute path
 */
string resolv_path(string curr, string tet)
{
    int i;
    string* tmp;
    string t1;

    if (curr && (curr == "cwd") && this_player()) {
        curr = (string)this_player()->get_path();
    }
    if (!tet || tet == ".") {
        return curr;
    }
    if ((tet == "here") && this_player()) {
        return file_name(environment(this_player())) + ".c";
    }
    if (tet == "~" || tet == "~/") {
        tet = user_path((string)this_player()->query_name());
    }
    if (sscanf(tet, "~/%s", t1)) {
        tet = user_path((string)this_player()->query_name()) + t1;
    }else if (sscanf(tet, "~%s", t1)) {
        tet = user_path(t1);
    }else if (tet[0] != '/') {
        tet = curr + "/" + tet;
    }

    if (tet[strlen(tet) - 1] != '/') {
        tet += "/";
    }
    tmp = explode(tet, "/");
    if (!tmp) {
        tmp = ({ "/" });
    }
    for (i = 0; i < sizeof(tmp); i++) {
        if (tmp[i] == "..") {
            if (sizeof(tmp) > 2) {
                tmp = tmp[0..(i - 2)] + tmp[(i + 1)..(sizeof(tmp) - 1)];
                i -= 2;
            } else {
                tmp = tmp[2..(sizeof(tmp) - 1)];
                i = 0;
            }
        }
    }
    tet = "/" + implode(tmp, "/");
    if (tet == "//") {
        tet = "/";
    }
    return tet;
}
