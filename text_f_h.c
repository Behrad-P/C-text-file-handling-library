
/**
 * @author  Behrad Pourhadi
 * @email   behradp32@gmail.com
 * @ide     Visual Studio Code
 * @brief   C text file handling library (.c)
*/


#include "text_f_h.h"
#include <stdio.h>
#include <string.h>


char Write_All(char *File_Name, char * Txt)
{
    FILE *Objfile = NULL;
    char Status = 0;
    
    Objfile = fopen(File_Name, "w");
    if(Objfile == NULL)
        Status = 1;
    else
    {
        fprintf(Objfile, "%s", Txt);
        fclose(Objfile);
    }
    
    return Status;
}

char Modify_Record(char *File_Name, char *Field_Name, char *Txt, int Field_Num)
{
    FILE *Objfile = NULL, *Tempfile = NULL;
    char str[MAX_FIELD_CHAR] = {0};
    char Obj_str[MAX_FIELD_CHAR] = {0};
    int Delete_Rep = Field_Num;
    char Temp_File_Name[] = "Tempfile.txt";
    char Status = 0, Search_Status = 0;
    char Line_Offset = 0;
    
    Tempfile = fopen(Temp_File_Name, "w");
    Objfile = fopen(File_Name, "r");
    if(Objfile == NULL || Tempfile == NULL)
        Status = 1;
    else
    {
        Search_Status = 2;
        strcpy(Obj_str, Field_Name);
        
        fscanf(Objfile, "%[^\n]s", str);
        if(strcmp(Obj_str, str) != 0)
            strcat(Obj_str, "\n");
        
        else    
            Line_Offset = -1;
            
        do{
          
            if(strcmp(Obj_str, str) == 0 || (Delete_Rep > Line_Offset && Delete_Rep < Field_Num))
            {
                if(Search_Status != 0)
                    fprintf(Tempfile, "%s", Txt);
                    
                Search_Status = 0;
                Delete_Rep--;
            }
                
            else
                fprintf(Tempfile, "%s", str);
                
        }while(fgets(str, sizeof(str), Objfile) != NULL);
        
        fclose(Tempfile);
        fclose(Objfile);
        
        remove(File_Name);
        rename(Temp_File_Name, File_Name);
    }
    
    return Status + Search_Status;    
}

char Append_Record(char *File_Name, char *Txt)
{
    FILE *Objfile = NULL;
    char Status = 0;
    
    Objfile = fopen(File_Name, "a");
    if(Objfile == NULL)
        Status = 1;
    else
    {
        fprintf(Objfile, "%s", Txt);
        fclose(Objfile);
    }
    
    return Status;    
}

char Read_Record(char *File_Name, char *scr, char *Field_Name, int Field_Num)
{
    FILE *Objfile = NULL;
    char str[MAX_FIELD_CHAR] = {0};
    char Temp_str[MAX_FIELD_CHAR] = {0};
    char Obj_str[MAX_FIELD_CHAR] = {0};
    int Read_Rep = Field_Num;
    char Status = 0, Search_Status = 0;
    char Line_Offset = 0;
    
    Objfile = fopen(File_Name, "r");
    if(Objfile == NULL)
        Status = 1;
    else
    {
        Search_Status = 2;
        strcpy(Obj_str, Field_Name);
        
        fscanf(Objfile, "%[^\n]s", str);
        if(strcmp(Obj_str, str) != 0)
            strcat(Obj_str, "\n");

        else    
            Line_Offset = -1;
        
        do{
          
            if(strcmp(Obj_str, str) == 0 || (Read_Rep > Line_Offset && Read_Rep < Field_Num))
            {
                strcat(scr, str);
                Search_Status = 0;
                Read_Rep--;
            }
                
        }while(fgets(str, sizeof(str), Objfile) != NULL);
        
        fclose(Objfile);
    }
    
    return Status + Search_Status;     
}

char Read_All(char *File_Name, char *scr)
{
    FILE *Objfile = NULL;
    char Status = 0;
    
    Objfile = fopen(File_Name, "r");
    if(Objfile == NULL)
        Status = 1;
        
    else
    {
        fscanf(Objfile, "%[^EOF]s", scr); 
        fclose(Objfile);
    }
    
    return Status;     
}

char Delete_Record(char *File_Name, char *Field_Name, int Field_Num)
{
    FILE *Objfile = NULL, *Tempfile = NULL;
    char str[MAX_FIELD_CHAR] = {0};
    char Obj_str[MAX_FIELD_CHAR] = {0};
    int  Delete_Rep = Field_Num;
    char Temp_File_Name[] = "Tempfile.txt";
    char Status = 0, Search_Status = 0;
    char Line_Offset = 0;
    
    Tempfile = fopen(Temp_File_Name, "w");
    Objfile = fopen(File_Name, "r");
    if(Objfile == NULL || Tempfile == NULL)
        Status = 1;
    else
    {
        Search_Status = 2;
        strcpy(Obj_str, Field_Name);
        
        fscanf(Objfile, "%[^\n]s", str);
        if(strcmp(Obj_str, str) != 0)
            strcat(Obj_str, "\n");

        else    
            Line_Offset = -1;
       
        do{
          
            if(strcmp(Obj_str, str) == 0 || (Delete_Rep > Line_Offset && Delete_Rep < Field_Num))
            {
                Search_Status = 0;
                Delete_Rep--;
                continue; 
            }
                
            else
                fprintf(Tempfile, "%s", str);
                
        }while(fgets(str, sizeof(str), Objfile) != NULL);
        
        fclose(Tempfile);
        fclose(Objfile);
        
        remove(File_Name);
        rename(Temp_File_Name, File_Name);
    }
    
    return Status + Search_Status;       
}
