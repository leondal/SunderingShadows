#include <daemons.h>
#include <std.h>

inherit DAEMON;

int cmd_netstats() {
        object ob;
        string out;
        mapping temp;
        float one, two;

        ob = NETWORK_D;
        temp = ob->network_stats();
        one = to_float(temp["total hits"]) / to_float(temp["net uptime"]);
        two = one * 60;
        out = "Network Statistics -- ShadowGate\n";
        out += "--------------------------------\n";
        out += "\n";
        out += "Total Hits............"+temp["total hits"]+"\n";
        out += "Network Uptime ......."+temp["net uptime"]+"\n";
        out += "Hits Per Minute......."+two+"\n";
        out += "Hits Per Second......."+one+"\n";
        out += "\n";
        out += "Date of Report : "+ctime(time())+"\n";
        write(out);
        return 1;
}
