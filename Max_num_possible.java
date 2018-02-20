
public class Max_num_possible {
	
	private String swap(String str,int i,int j){
		char[] arr = str.toCharArray();
		char temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		return new String(arr);
	}
	
	private String maxnum(String str,int k,String max){
		if(k==0)
			return max;
		
		int n = str.length();
		
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				
				if(str.charAt(i)>str.charAt(j)){
					str = swap(str,i,j);
				}
				
				if(str.compareTo(max)>0){
					max=str;
					//System.out.println(max);
				}
				
				maxnum(str,k-1,max);
				
				str = swap(str,i,j);
			}
		}
		return max;
	}
	
	public static void main(String[] args){
		String str = "129814999";
		String max = str;
		Max_num_possible obj = new Max_num_possible();
		max = obj.maxnum(str,4,max);
		System.out.println(max);
	}
}
