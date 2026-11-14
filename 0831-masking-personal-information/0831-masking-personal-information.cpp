class Solution {
public:
    string maskPII(string s) {
        size_t atIndex = s.find('@');

        if (atIndex != string::npos) {
            string maskedEmail;
            maskedEmail.push_back(tolower(s[0]));
            maskedEmail += "*****";
            maskedEmail.push_back(tolower(s[atIndex - 1]));
            maskedEmail += s.substr(atIndex);

            for (char &character : maskedEmail) {
                character = tolower(character);
            }

            return maskedEmail;
        }

        string digits;
        for (char character : s) {
            if (isdigit(character)) {
                digits.push_back(character);
            }
        }

        string maskedPhone;
        int countryCodeLength = digits.size() - 10;

        if (countryCodeLength > 0) {
            maskedPhone.push_back('+');
            maskedPhone.append(countryCodeLength, '*');
            maskedPhone.push_back('-');
        }

        maskedPhone += "***-***-";
        maskedPhone += digits.substr(digits.size() - 4);

        return maskedPhone;
    }
};