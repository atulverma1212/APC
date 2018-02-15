
public class String_Permutation {
	private void permute(String str,int l,int r){
		if(l==r)
			System.out.println(str);
		else{
			for(int i=l;i<=r;i++){
				str = swap(str,l,i);
				permute(str,l+1,r);
				str = swap(str,l,i);
			}
		}
	}
	
	private String swap(String str,int l,int r){
		char arr[] = str.toCharArray();
		char temp = arr[l];
		arr[l] = arr[r];
		arr[r] = temp;
		return new String(arr);
	}
	
	public static void main(String args[]){
		String string = "ABC,DAG";
		String_Permutation permute = new String_Permutation();
		permute.permute(string, 0, string.length()-1);
	}
}