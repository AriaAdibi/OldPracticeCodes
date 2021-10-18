# run me in the folder that contains folders with name id_n_name
# v 1.0

import csv
import os
import shutil

CUR_PATH= os.getcwd()
MARKINGS_CSV_NAME= "COMP 339 - Markings - Assignment 1.csv"

paths= []

# ------------------------------------------------------------------------------
col_widths= [15, 20, 30]
len_row_seperation= 83
len_sec_seperation= 93

#TODO for some reason I have to increase the tol for the code to work properly
tol_width= 10 #all the sentences "must" have tol_width space till the "hard line," unless the word forces to enter the tol region.
comment_width= len_sec_seperation - col_widths[0] - col_widths[1] - tol_width

def print_sep_line(f, type):
    assert (type == 'sec' or type == 'row'), 'The given type to "print_sep_line" is incorrect.'

    if type == 'sec':
        f.write( '+{:-<{len_sec_seperation}}\n'.format('', len_sec_seperation= len_sec_seperation) )
    elif type == 'row':
        f.write( '+{:-<{len_row_seperation}}\n\n'.format('', len_row_seperation= len_row_seperation) )

def fit_in_width_str(str_, width, is_first_line):
    #the str_ does not have any '\n'
    the_space= ' ' * (col_widths[0] + col_widths[1])
    fitted_str_= '' if is_first_line else the_space
    words= str_.split()

    current_len= 0
    for word in words:
        fitted_str_ += (word + ' ')
        current_len += len(word) + 1
        if current_len >= width:
            fitted_str_= fitted_str_.rstrip() + '\n' + the_space
            current_len= 0

    return fitted_str_.rstrip()

# ------------------------------------------------------------------------------

with open("dont_delete_me.txt", "r") as f:
    paths = [l.strip() for l in f.readlines()]
    paths = [p.split("/") for p in paths]

with open(MARKINGS_CSV_NAME) as f:
    csv_reader = csv.reader(f, delimiter=",")

    header= next( csv_reader ) #Raises StopIteration if empty. First row assumed to be the header.

    for row in csv_reader:

        student_id= row[0]
        with open("mark.txt", "w") as f_mark:
            #The message
            f_mark.write( 'Hello {},\n\n'.format(student_id) )
            f_mark.write( 'The following is your grades in assignment one. Each question has one point.\n\
Note that it is not guaranteed that you get the same score in your exam, duo to the somewhat lenient approach of marking the assignments. Nevertheless, in the presence of mistakes, I tried to point out as many of them as I could. Please follow the professor\'s guidelines for writing in your exam.\n\n\
General notes (written for everyone):\n\
\t 1. Please write legibly; if not, you would get 0. Please consider this warning seriously.\n\
\t 2. Please submit your assignment as "FULLNAME_STUDENTID."\n\
\t 3. Please somehow indicate your final answer. It is not required if you to calculate the numerical value.\n\
\t 4. Please explain yourself, most of the time prove it. Note that does not mean writing a long or being too formal but leave no "reasoning-gap" in your argument.\n\
\n\nThank you.\n' )
            print_sep_line(f_mark, 'sec')
            f_mark.write( '\n\n' )

            print_sep_line(f_mark, 'sec')
            print_sep_line(f_mark, 'sec')
            f_mark.write( '{:<{w0}}'.format( 'Question', w0= col_widths[0] ) )
            f_mark.write( '{:<{w1}}'.format( 'Grade', w1= col_widths[1] ) )
            f_mark.write( '{:<{w2}}\n'.format( 'Comment(s)', w2= col_widths[2] ) )
            print_sep_line(f_mark, 'sec')
            print_sep_line(f_mark, 'sec')


            for r, h in zip(row, header):
                if h == 'Submission Time' or h == 'STUDENT ID':
                    continue

                if h == '' or 'Comment' in h:
                    #the_comment -----------------------------------------------
                    the_comment= r if( str(r) != 'nan' ) else ''
                    the_comment_lines= the_comment.split('\n')

                    f_mark.write( '{:<{w2}}\n'.format( fit_in_width_str( the_comment_lines.pop(0), comment_width, True ), w2= col_widths[2] ) ) #first line - no spacing needed
                    for line in the_comment_lines:
                        f_mark.write( '{:<{w2}}\n'.format( fit_in_width_str( line, comment_width, False ), w2= col_widths[2] ) )

                    f_mark.write('\n')
                    print_sep_line(f_mark, 'row')

                else:
                    #the_question_part
                    str_= h.rstrip('0').rstrip('.') + ':'
                    f_mark.write( '{:<{w0}}'.format( str_, w0= col_widths[0] ) )

                    #the grade #no 'nan' is assumed
                    str_= ''
                    if r != '' and r != ' ': #TODO
                        the_grade= float(r)
                        str_= '{:.6f}'.format(the_grade).rstrip('0').rstrip('.')
                    f_mark.write( '{:<{w1}}'.format( str_, w1= col_widths[1] ) )

        for p in paths: #We have multiple p having same parent path. However, ok. No conflict.
            if p[0] == student_id: #p[0] is . because ./ ...
                mkdir_dir_path= CUR_PATH + '/'
                for i in range( 1, len(p) - 1 ): #last element is the file names
                    mkdir_dir_path += p[i] + '/'
                    os.mkdir(mkdir_dir_path)

                shutil.move( CUR_PATH + '/mark.txt', mkdir_dir_path)
                break
