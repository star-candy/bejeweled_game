
# ��� ���

## puzzle.cpp/.h �����ϱ�

- puzzle.cpp
  + [0] getjewelLetter function ���� (���� type�� �´� text ��ȯ) 
	
  + [0] getJewlType function ���� (text �Է½� �Է¿� �ش��ϴ� ���� type ��ȯ)
	
  + [0] puzzle constructor (������ ����, ���� ������ ���ڷ� ����, �� + �� ũ�⸦ vector ũ���)
	+ ��� jewel �� NONE���� �ʱ�ȭ
	+ vector ���� jewels
	
  + [0] initialize (�Է¹��� jewel_list_���ڿ��� ���� ��� jewel�� �ʱ�ȭ)
	+ jewel_list���ڿ��� getJewelType�� ���� jewel type���� ����_
	+ jewel vector�� jewel_list���� ����ġ�� false return_
	
  + [0] randomize (��� jewel�� �����ϰ� �ʱ�ȭ)
	+ rand�� enum ��ü �������� int�� jewel type ��ȯ
	
  + [] update (chain ���� �� jewel vector�� update ����)
	+ A : ��� ü�� �ĺ�(����, ���� ����), NONE type���� ����
		+ [0] validCount : �˻� ������ jewels vector �������� �Ǵ�
		+ [0] identifyChain : chain ���� ���� �˻� �� chains vector�� ����
		+ [0] claerChain : chain ��ǥ�� ���Ե� jewels�� type�� NONE���� ����
	+ B : NONE type jewel�� ���� ���� ����߷� ä���, ���� ������� �����ϰ� �ſ��
		+ [ ] fillJewels : none type�� jewels�� �����ϰ� �� ä���ֱ�
	+ update ȣ�� �� A, B ��� �� �ϳ� ����
	+ A B ����� ����ȴٸ� true, chain�� ���� �� false ��ȯ
	
  + [] setJewel (���� ��ǥ, jewel ������ ���ڷ� �޾� ���� ���� ����)
	+ ��ǥ�� ����, Ȥ�� jewel vector�� ũ�� �ܺο� ���� �� false ��ȯ
	+ vector ���ο� ���� �� ���� �� true ��ȯ

  + [] getJewel (���� ��ǥ�� ���ڷ� ����)
	+ ��ǥ ��ȿ �� �ش� ��ǥ�� ���� type�� return
	+ ����ȿ ��ǥ �� NONE type�� return
	
  + [] swapJewels (swap ���� ���� ��ǥ 2���� ���ڷ� ����)
	+ ��ǥ ��ġ ����(jewel vector ���� �ִ°�, �� ��ġ�� �����Ѱ�)->false ��ȯ
	+ jewels vector���� �� ��ǥ�� type swap -> true ��ȯ
	
## ����� ui �����ϱ�
- main_text.cpp
  + []
