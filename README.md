# C-text-file-handling-library

**Create your text files in the easiest way in c/c++ language and enjoy**

__Example:__


~~~

#include <stdio.h>
#include "text_f_h.h"

char fstr[50];

int main()
{

    Write_All("t.txt", "kiwi:\n20 Kg\n5 $");
    Append_Record("t.txt", "\norange:\n50 Kg\n2 $");
    Append_Record("t.txt", "\nmelon:\n70 Kg\n10 $");

    Read_Record("t.txt", fstr, "kiwi:", 3);
    printf("%s\n", fstr);

    Delete_Record("t.txt", "kiwi:", 3);

    if(Read_Record("t.txt", fstr, "kiwi:", 3) != 0)
        printf("selected field not found Or The file was not created correctly\n");
    else
        printf("%s\n", fstr);

    Modify_Record("t.txt", "orange:", "orange:\n5 Kg\n8 $\n", 3);
    Delete_Record("t.txt", "melon:", 3);

    Read_All("t.txt", fstr);
    printf("%s\n", fstr);

    return 0;
}

~~~

**OUtput:**

~~~

selected field not found Or The file was not created correctly
orange:
5 Kg
8 $

~~~

