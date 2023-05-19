from datetime import timedelta, datetime

def contest_duration(name, hours=5):
    now = datetime.now()
    arrival = now + timedelta(hours=hours)
    return arrival.strftime(f"contest {name}'s duration untill: %A %H: %M")

contest_duration("EDAI")
contest_duration("CPCFI", hours=0.45)