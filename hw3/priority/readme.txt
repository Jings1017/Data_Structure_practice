eval.cpp

����Jprefix
�i�J��for-loop�̭�
��if-else�P�_string���C�@��s�������
�p�G�O�Ů� �hcontinue
�p�G�O�Ʀr �N�Ʀrpush��stack��
�䤤 �]��J�G��Ʈɷ|�����D �G�A��if-else�i��P�_�B�z
�p�G�O+-*/ �h�Nstack���̤W����Ӽ�pop�X�Ӷi��B��  
�⧹����Apush�istack��
for-loop run������ �Nstack�����ȿ�X�Y�ҨD

*********************************************************
prefix.cpp

�D�{��:
�ŧiinfix�Ascan infix�A
����function in2pre �A�����{��

�Ƶ{��priority:
�Ѧҽҥ��A�w�q�U�ӹB��l���v���A��K�D�{���ϥ�

�Ƶ{��in2pre:
�D�n�O�Ninfix�নprefix
�Q��strlen�p��r��j�p
�i��while(1)�j��
����switch case ���������k�A���B��L�B��l�B�B�⤸

��L�B��l:
�o�̥u�B�z�Q�ؤ��P���B��l�A
���v��(�Ƶ{��)����j�p�A
�v�����j�̥i���L�v�����p�̡A�Gpush�istack
�Ϥ��A�v�����p�̵L�k���L�v�����j�̡A
�ݥ��Nstack���v�����j��pop�X��

���k�A��:
��J��k�A���ɡA�N���᪺�B��lpush�istack�A
����J�쥪�A���A�h�N�o�@�q���B��lpop�X��

�B�⤸:
�o���k���bdefault�̡A
�J��B�⤸�h������Jprefix��

����infix���Ҧ��������B��A
�̫�Nprefix�f�m�Y���ҨD�C

