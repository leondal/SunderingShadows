//      /bin/dev/_eval.c
//      Part of the TMI distribution mudlib and now part of Nightmare's
//      allows wizards to execute LPC code without writing new objects.
//      Created by Douglas Reay (Pallando @ TMI-2, Nightmare, etc) 92-12-07

#include <security.h>
#include <std.h>

inherit DAEMON;

#define SYNTAX "Syntax: \"eval <lpc commands>\".\n"

int cmd_eval(string a)
{
    string file, filename;
    mixed err, ret;
    string what;
    int wee;
    if (!a) {
        notify_fail(SYNTAX); return 0;
    }
    if (sscanf(a, "%s->set_level(%d)", what, wee) == 2) {
        return 0;
    }
    seteuid(UID_ROOT);
    write_file("/log/adm/evals", ctime(time()) + ": " + capitalize(TPQN) + " " + a + "\n");
    seteuid(geteuid());
    seteuid(getuid(previous_object()));
    file = "" +
        "#include <std.h>\n" +
        "#include <daemons.h>\n" +
        "#include <runtime_config.h>\n" +
        "inherit OBJECT;\n" +
        "void create() { seteuid( getuid() ); }\n" +
        "mixed eval() { " + a + "; }\n" +
        "";
    filename = user_path(geteuid(this_player()));
    if (file_size(filename) != -2) {
        notify_fail("You must have a valid home directory!\n");
        return 0;
    }
    // filename = TMP_DIR + geteuid( this_player() ) + "_eval.c";
    filename += "CMD_EVAL_TMP_FILE.c";
    // long name so won't coincide with file already in your directory by accident
    rm(filename);
    if (ret = find_object(filename)) {
        destruct(ret);
    }
    write_file(filename, file);
    if (err = catch(ret = (mixed)call_other(filename, "eval"))) {
        write("Error = " + err);
        (mixed)call_other(filename, "eval");
    }else {
        write(wrap("Result = " + identify(ret)));
    }
    //rm( filename );
    if (ret = find_object(filename)) {
        destruct(ret);
    }
    // Some muds prefer to change these lines so filename isn't deleted if
    // an error occurs.  Also, if you don't have the identify() simul_efun
    // the less through dump_variable() simul_efun can be used instead.
    return 1;
}

int help()
{
    write (SYNTAX + @EndText
           Effect:   calls a function containing < lpc commands >
           Example:  If you type:
           eval return 1 + cos(0.0)
           the command creates a temporary file in your home dir containing the line:
           eval()
           {
               return 1 + cos(0.0);
    }
           then does call_other on the files 's eval() function, giving:
  Result = 2.000000
EndText
  );
  return 1;
}
