
/**
 * @author  Behrad Pourhadi
 * @email   behradp32@gmail.com
 * @ide     Visual Studio Code
 * @brief   C text file handling library (.h) 
*/


#ifndef __TEXT_F_H__
#define __TEXT_F_H__

#ifdef __cplusplus
 extern "C" {
#endif


/** The maximum number of characters in each field */
#define MAX_FIELD_CHAR 50 

/**
 * @brief  Writes text or a record to a file.
 * @note   If the file already contains text, it deletes it and replaces it with the new text "Txt".
 * @param  File_Name: The name of the file.
 * @param  Txt: The text to be written to the file.
 * @retval 0: The file is created correctly (no error).
 * @retval 1: The file was not created correctly.
 */
char Write_All(char *File_Name, char *Txt);

/**
 * @brief  Modifies a record or fields of a record.
 * @param  File_Name: The name of the file.
 * @param  Field_Name: The name of the field to be changed.
 * @param  Txt: The text to be written to the file instead of the selected field or record.
 * @param  Field_Num: The number of fields to change.
 * @retval 0: The file is created correctly (no error).
 * @retval 1: The file was not created correctly.
 * @retval 2: The selected field (Field_Name) was not found.
 */
char Modify_Record(char *File_Name, char *Field_Name, char *Txt, int Field_Num);

/**
 * @brief  Appends a record or field to a file.
 * @param  File_Name: The name of the file.
 * @param  Txt: The text to be appended to the file.
 * @retval 0: The file is created correctly (no error).
 * @retval 1: The file was not created correctly.
 */
char Append_Record(char *File_Name, char *Txt);

/**
 * @brief  Reads a record or fields of a record from a file.
 * @param  File_Name: The name of the file.
 * @param  scr: The string in which the read record or field should be stored.
 * @param  Field_Name: The name of the field to be read.
 * @param  Field_Num: The number of fields to read.
 * @retval 0: The file is created correctly (no error).
 * @retval 1: The file was not created correctly.
 * @retval 2: The selected field (Field_Name) was not found.
 */
char Read_Record(char *File_Name, char *scr, char *Field_Name, int Field_Num);

/**
 * @brief  Reads the entire contents of a file.
 * @param  File_Name: The name of the file.
 * @param  scr: The string in which the entire read file should be stored.
 * @retval 0: The file is created correctly (no error).
 * @retval 1: The file was not created correctly.
 */
char Read_All(char *File_Name, char *scr);

/**
 * @brief  Deletes a record or fields of a record from a file.
 * @param  File_Name: The name of the file.
 * @param  Field_Name: The name of the field to be deleted.
 * @param  Field_Num: The number of fields to delete.
 * @retval 0: The file is created correctly (no error).
 * @retval 1: The file was not created correctly.
 * @retval 2: The selected field (Field_Name) was not found.
 */
char Delete_Record(char *File_Name, char *Field_Name, int Field_Num);


#ifdef __cplusplus
}
#endif


#endif /* __TEXT_F_H__ */

