
//      /adm/simul_efun/wrap.c
//      Part of the TMI distribution mudlib and now Nightmare's
//      Inserts "\n"'s into text so lines arn't wider than screens
//      Author unknown, but thanks to the MudOS driver team for sprintf
//      Moved to Nightmare by Pallando 93-05-28

/**
 * @file
 */

/**
 * Wraps the string, adding newlines
 */
varargs string wrap(string str, int x)
{
    if( !x ) {
        if( !this_player() ) x = 79;
        else {
            int tmp;

            tmp = (int)this_player()->getenv("SCREEN");
            if( tmp ) x = (tmp || 79);
            else x = 79;
        }
    }
    if(sizeof(str) < 7900) return sprintf("%-=" + x + "s\n", str);
    else {
        string tmpfile = generate_tmp();
        write_file(tmpfile,str);
        str = read_bytes(tmpfile,0,7900);
        rm(tmpfile);
        str += "\n*** TRUNCATED ***\n";
        return sprintf("%-=" + x + "s\n", str);
    }
}
