// https://www.nowcoder.com/practice/b56799ebfd684fb394bd315e89324fb4?tpId=117
// �������ڣ�����left�������������ظ���Ӵ�
class Solution {
public:
    int maxLength(vector<int>& arr) {
        int mx = 0, left, key;
        int n = arr.size();
        map<int, int> mp; // ֵ-����
        
        left = 0;
        for(int i=0; i<n; i++) {
            key = arr[i];
            if(mp.find(key) != mp.end()) {
                mx = max(mx, i-left);
                left = max(left, mp[key]+1);
            } else {
                mx = max(mx, i-left+1);
            }
            mp[key] = i; // ��������
        }
        return mx;
    }
};
