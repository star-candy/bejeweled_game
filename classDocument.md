
# ��� ���

## puzzle.cpp/.h �����ϱ�

- puzzle.cpp
  + [] getjewelLetter function ���� (���� type�� �´� text ��ȯ) 
	
  + [] getJewlType function ���� (text �Է½� �Է¿� �ش��ϴ� ���� type ��ȯ)
	
  + [] puzzle constructor (������ ����, ���� ������ ���ڷ� ����, �� + �� ũ�⸦ vector ũ���)
	+ ��� jewel �� NONE���� �ʱ�ȭ
	+ vector ���� jewels
	
  + [] initialize (�Է¹��� jewel_list_���ڿ��� ���� ��� jewel�� �ʱ�ȭ)
	+ jewel_list���ڿ��� getJewelType�� ���� jewel type���� ����_
	+ jewel vector�� jewel_list���� ����ġ�� false return_
	
  + [] randomize (��� jewel�� �����ϰ� �ʱ�ȭ)
	+ rand�� enum ��ü �������� int�� jewel type ��ȯ
	
  + [] update (chain ���� �� jewel vector�� update ����)
	+ A : ��� ü�� �ĺ�(����, ���� ����), NONE type���� ����
	+ B : NONE type jewel�� ���� ���� ����߷� ä���, ���� ������� �����ϰ� �ſ��
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
