Chinese Postman Problem Report

�m�W�G�����p
�Ǹ��GN26074922

�p��sĶ�G
  �b�ڥؿ��U����U�C���O
  $ make && ./main.out
  �Y�i�b�׺ݾ����ݨ���浲�G
  �æb���ͥX��RESULT.txt���ݨ���|����


�{���]�w�G
�@�ڳo����@������l�t���D�O�ϥ�"�L�V��"�B"�L�v��"������
  �B�ѩ��D�بS���]�w��J�I���Ӽ�
  �]���ڪ��{���]�w���ȯ�̦h����10���I
  �åB�u�ݦbtopo.txt���]�w�䤤�@����
  �ڧY�|�b�{�����N�t�@����ɤW�w�q���L�V��
  �]���u���w�q�@����Y�i  (ex. a b 1 1)
  �ܩ�capacity�H��flow�b���{�����S���ϥΨ�A�]���i�H�H�N����


���D����G
  1. �Q�ΧU�Ъ�interpret API�N�ϥ�txt�ɴy�z�n�ÿ�J
  2. �A�ϥ�connected API�P�_���I�����O�_�s�u�ӫإ�adjacency matrix
  3. �Q�Ϋإߦn��adjacency matrix�ӧP�_�����I��order���_��
  4. �Q��"Dijkstra�t��k�N�Z���`�M�̵u���t��զX�D�X��
  5. �N�t�諸�_���I����ç�sadjacency matrix�����שԹ�
  6. �Q��DFS�t��k�N�w�g��s��adjacency matrix���|����

  �W�z6�I���ڪ��D�n���D����A�U���|���W�z���I����Ӹ`������

�{����@�G
  ����������l�t���D�n�D���ݭn���L�Ϥ��Ҧ�����ܤ֤@���B�n�D���|���̵u
  �]���b�{���@�}�l�N���ǥ�API��J�ܵ{������A�ڷ|�N�_��order���I��X��
  ���ҥH�n��_��order�I����]�O�A�p�G�@�i�Ϥ��Ҧ��I��order�Ҭ�����
  ���Ϻ٬��שԹϡA�b�שԹϤ��@�w�i�H���@�Ӱj���N�Ҧ��I���g�L�@���åB�^����I
  �]���Y��J�ϥ������O�שԹϡA�����ڷ|���N�o�ɦ��שԹ�
  �]���_��order������degree-sum formula�|����X�{
  �]����M�_���I�������̵u���|�H�Ϊ��׬O�ɹϪ����n�u�@
  �ڧ�M�̵u���|����k�O�ϥ�"Dijkstra's algorithm"
  ���t��k�i�H�Ψӧ�M���I�������̵u���|
  �ڱq�����W�ѦҤF���t��k�ð��F�@�ǭק�
  �]������ڰѦҪ�Dijkstra's algorithm�{���Ȧ��̵u����
  �ڥ[�W�F�̵u�����|��trace�A�]���ڥi�H���̵u�����|�æs�i�}�C��
  �ǥѦ��t��k�̵u���|����M�A�ڴN�i�H�N�̵u���_���I�t��ù��i�����
  �p���@�ӴN��o��ɧ���������׳̵u���שԹ�
  �b�o��שԹϤ���A�ڷ|�i��שԦ^�����M��
  �שԦ^�����M��ڬO�Q��DFS�A"�`���u���j�M�t��k"
  �åB�N���|print�X�ӥB�g���ɮפ������y�{�C
                                                            ----
���浲�G�G                                                 /    \
  �H�ڦbgithub�W���Ҥl�|�ҡA��J�@���`��6���I       a------f-----c
  �_��order�I��4���I����(�p�k��)�A����DFS����       |    //|\\
  �|�Ѱ_�I"a"�}�l���è����Ҧ���N���G��X�p�U       |   // | \\
  a b d f b f c f e f a                             |  //  |  \\
  �ó̫��adjacency matrix��X�ˬd�O�_�Ҭ�0         | //   |   \\
  �Ҭ�0�N��w�N�Ҧ����|�����C                       |//    |    \\
                                                    b------d     e

BONUS�G
  �b�ڹ�@��project�ɡA�b������interpret�����V�s���ɵo�{�Fbug
  �g�L�P�U�аQ�סA�T��O�{����bug


�Ѧҳs���G
  [1]https://www.geeksforgeeks.org/dijkstras-shortest-path-with-minimum-edges/fbclid=IwAR2XtFJXYBbffodIMhqsxKuCJpPDiyf-8oOkY6aUtwtchnkAC_-10OevxNs
  
  [2]https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/



