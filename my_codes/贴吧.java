/*************************************************************************
	> File Name: 贴吧.java
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年02月18日 星期日 11时34分24秒
 ************************************************************************/
import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;

public class 贴吧 {

 public static void main(String[] args) throws UnsupportedEncodingException{
  String a="%E4%B8%AD%E6%95%A3%E5%8F%94%E5%A4%9C%E4%B8%8B%E5%8F%B0";
  System.out.println(URLDecoder.decode(a,"UTF-8"));
}
}
