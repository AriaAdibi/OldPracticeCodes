import pandas as pd

THE_REL_PATH= 'Combinatorics A4 Markings - Markings.csv'
X= pd.read_csv(THE_REL_PATH, header= 0)
X= X.drop( columns= X.columns[-1] ) #deleting the Sum column
X= X.values.tolist()

titles= X[0]
#----------
X= X[1:]

q_nums= [2, 3, 4, 6, 8, 10, 11, 12, 13]
num_parts= [1, 1, 4, 2, 2, 1, 1, 1, 1]

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

def fit_in_width_str(str_, w, is_first_line):
    #the str_ does not have any '\n'
    the_space= ' ' * (col_widths[0] + col_widths[1])
    fitted_str_= '' if is_first_line else the_space
    words= str_.split()

    current_len= 0
    for word in words:
        fitted_str_ += (word + ' ')
        current_len += len(word) + 1
        if current_len >= w:
            fitted_str_= fitted_str_.rstrip() + '\n' + the_space
            current_len= 0

    return fitted_str_.rstrip()

for r in X:
    ID= r[0]
    with open('mark_{}.txt'.format(ID), 'w') as f:
        #The message
        f.write( 'Dear {},\n\n'.format(ID) )
        f.write( 'The following is your grades in the selected questions of assignment four.\nEach question has 1 point which is divided equally between its parts.\n\nThank you.\n' )
        print_sep_line(f, 'sec')
        f.write( '\n\n' )

        print_sep_line(f, 'sec')
        print_sep_line(f, 'sec')
        f.write( '{:<{w0}}'.format( 'Question', w0= col_widths[0] ) )
        f.write( '{:<{w1}}'.format( 'Grade', w1= col_widths[1] ) )
        f.write( '{:<{w2}}\n'.format( 'Comment(s)', w2= col_widths[2] ) )
        print_sep_line(f, 'sec')
        print_sep_line(f, 'sec')

        col_indx= 1
        for i in range( len(q_nums) ):
            f.write( 'Q{}:\n'.format( q_nums[i] ) )

            for j in range( num_parts[i] ):
                #the_question_part
                str_= str(titles[col_indx]).rstrip('0').rstrip('.') + ':'
                f.write( '{:<{w0}}'.format( str_, w0= col_widths[0] ) )
                #the grade #no 'nan' is assumed
                the_grade= float(r[col_indx]) / num_parts[i]
                str_= '{:.6f}'.format(the_grade).rstrip('0').rstrip('.')
                f.write( '{:<{w1}}'.format( str_, w1= col_widths[1] ) )
                col_indx += 1

                the_comment= r[col_indx] if( str( r[col_indx] ) != 'nan' ) else ''
                the_comment_lines= the_comment.split('\n')
                #the_comment ---------------------------------------------------
                f.write( '{:<{w2}}\n'.format( fit_in_width_str( the_comment_lines.pop(0), comment_width, True ), w2= col_widths[2] ) ) #first line - no spacing needed
                for line in the_comment_lines:
                    f.write( '{:<{w2}}\n'.format( fit_in_width_str( line, comment_width, False ), w2= col_widths[2] ) )
                #---------------------------------------------------------------
                # the_comment= the_comment.replace( '\n', '\n' + ' ' * (col_widths[0] + col_widths[1]) )
                # f.write( '{:<{w2}}\n'.format( the_comment, w2= col_widths[2] ) ) #the_comment
                col_indx += 1

            print_sep_line(f, 'row')
