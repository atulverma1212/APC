
public class KMP_algorithm {
	
	void preprocess(String str,int arr[]){
		int i=1,len=0;
		arr[0]=0;
		int N = str.length();
		while(i<N){
			if(str.charAt(i)==str.charAt(len)){
				len++;
				arr[i]=len;
				i++;
			}
			else{
				if(len!=0){
					len=arr[len-1];	
				} else {
					arr[i]=len;
					i++;
				}
			    
			}
		}
	}
	
	void search(String str,String pat){
		int N = str.length();
		int M=pat.length();
		int i=0,j=0;
		int lps[] = new int[M];
		preprocess(pat,lps);
		
		while(i<N){
			if(str.charAt(i)==pat.charAt(j)){
				i++;
				j++;
			}
			if(j==M){
				System.out.println("Pattern found at "+(i-j));
				j=lps[j-1];
			}
			if(i<N && str.charAt(i)!=pat.charAt(j)){
				if(j!=0)
					j=lps[j-1];
				else
					i++;
			}
		}		
	}
	
	public static void main(String[] args){
		String str = "bbbbbbbbab ";
		String pat = "baba";
		new KMP_algorithm().search(str, pat);
	}
}
