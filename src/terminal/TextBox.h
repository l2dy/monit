/*
 * Copyright (C) Tildeslash Ltd. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 *
 * You must obey the GNU Affero General Public License in all respects
 * for all of the code used other than OpenSSL.  
 */


#ifndef BOX_INCLUDED
#define BOX_INCLUDED


/**
 * Class for terminal table output.
 *
 * @author http://www.tildeslash.com/
 * @see http://www.mmonit.com/
 * @file
 */


typedef enum {
        TextBoxAlign_Left = 0,
        TextBoxAlign_Right
} __attribute__((__packed__)) TextBoxAlign_T;


typedef struct TexBoxColumn_T {
        const char *name;
        char *value;
        // Options
        int width;
        bool wrap;
        TextBoxAlign_T align;
        // Internal
        int _colorLength;
        unsigned long _valueLength;
        unsigned long _cursor;
        char _color[8];
} TextBoxColumn_T;


#define T TextBox_T
typedef struct T *T;


/**
 * Constructs a terminal table object.
 * @param b The output stringbuffer
 * @param columnsCount Count of table columns
 * @param columns Array of BoxColumn_T columns specification
 * @param printHeader true if the header should be printed otherwise false
 * @return A new terminal table object
 */
T TextBox_new(StringBuffer_T b, int columnsCount, TextBoxColumn_T *columns, bool printHeader); //FIXME: when OutputStream is added, use it instead of StringBuffer


/**
 * Close and destroy a Box object and free allocated resources
 * @param t a Box object reference
 */
void TextBox_free(T *t);


/**
 * Set a table column value
 * @param t The terminal table object
 * @param index Column index
 * @param format A format string with optional var args
 */
void TextBox_setColumn(T t, unsigned int index, const char *format, ...) __attribute__((format (printf, 3, 4)));


/**
 * Print a table row
 * @param t The terminal table object
 */
void TextBox_printRow(T t);


/**
 * Strip the UTF-8 table control characters in the string.
 * @param s The string to strip
 * @return A pointer to s
 */
char *TextBox_strip(char *s);


#undef T
#endif

